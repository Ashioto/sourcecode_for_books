/**
 * https://github.com/morris821028/UVa/
 * 本题相当重要
 * 在不同的时刻，接线员的权重不同，反映在D上。pair<int,int>
 * 同时对于每个staff来说，按顺序便利proc_list即可。
 */
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Staff
{
	int pid;
	vector<int> proc_list;
};
struct Job
{
	int tid;
	int start;
	int proc;
	Job (int t=0, int s=0, int p=0) {
		tid = t;
		start = s;
		proc = p;
	}
};
bool operator < (const Staff &a, const Staff &b)
{
	return a.pid < b.pid;
}
bool operator < (const pair<int,int> &a, const pair<int,int> &b)
{
	if (a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}
struct cmpJob {
    bool operator() (const Job &a, const Job &b) const {
        return a.start > b.start;
    }
};
int main()
{
	int M, N, kase = 0;
	while (cin >> N && N) {
		map<int,queue<Job> > scheduler;
		// map<int, priority_queue<Job, vector<Job>, cmpJob> > scheduler;
		priority_queue<int, vector<int>, greater<int> > timeline;
		int tid, num, t0, t, dt;
		for (int i = 0; i < N; i++) {
			cin >> tid >> num >> t0 >> t >> dt;
			for (int j = 0; j < num; j++) {
				scheduler[tid].push(Job(tid, t0, t));
				timeline.push(t0);
				t0 += dt;
			}
		}

		cin >> M;
		Staff staffs[10];
		for (int i = 0; i < M; i++) {
			int pid, k, tid;
			cin >> pid >> k;
			staffs[i].pid = pid;
			for (int j = 0; j < k; j++) {
				cin >> tid;
				staffs[i].proc_list.push_back(tid);
			}
		}

		sort(staffs, staffs+M); // sort by pid;
		// cout << staffs[1].pid << endl;
		int working[10] = {}, staReq[10] = {}, endReq[10] = {};
		int now = 0, totTime = -2;
		timeline.push(now);
		while (!timeline.empty()) {
			now = timeline.top();
			// cout << "now: " << now << endl;
			timeline.pop();
			if (totTime == now)
				continue;
			totTime = now;
			for (int i = 0; i < M; i++) {
				if (endReq[i] <= now)
					working[i] = 0;
			}
			vector<pair<int,int> > D;
			for (int i = 0; i < M; i++) {
				if (working[i] == 0)
					D.push_back(make_pair(staReq[i], i));
			}
			sort(D.begin(), D.end());
			for (int i = 0; i < D.size(); i++) {
				Staff u = staffs[D[i].second];
				for (int j = 0; j < u.proc_list.size(); j++) {
					int tid = u.proc_list[j];
					if (!scheduler[tid].empty()) {
						Job job = scheduler[tid].front();
						if (job.start <= now) {
							scheduler[tid].pop();
							working[D[i].second] = 1;
							staReq[D[i].second]  = now;
							endReq[D[i].second]  = now + job.proc;
							timeline.push(now + job.proc); // test
							break;
						}
					}
				}
			}
		}
		printf("Scenario %d: All requests are serviced within %d minutes.\n", ++kase, totTime);
	}
	return 0;
}

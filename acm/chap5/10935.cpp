/**
 * 熟悉queue的用法，无难度
 * q.front q.push q.pop
 */ 
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int i, j, k;
	while (cin >> n && n) {
		// initialize the queue
		queue<int> q;
		for (i = 1; i <= n; i++) {
			q.push(i);
		}
		// process 
		cout << "Discarded cards:";
		bool _first = true;
		while (q.size() >= 2) {
			if (_first)
				_first = false;
			else
				cout << ",";
			cout << " " << q.front();
			q.pop();
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		cout << "\n";
		// process the last numbers
		cout << "Remaining card: ";
		cout << q.front() << endl;

	}
	return 0;
} 

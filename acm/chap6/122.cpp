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

const int maxn = 1000;
int Left[maxn], Right[maxn], have_value[maxn], value[maxn], root, cnt;
bool failed;

void newtree()
{
	root = 1;
	Left[root] = Right[root] = 0;
	have_value[root] = false;
	cnt = 1;
}

int newnode()
{
	int u = ++cnt;
	Left[u] = Right[u] = 0;
	have_value[u] = false;
	return u;
}

void addnode(int v, string s)
{
	int u = root;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'L') {
			if (!Left[u])
				Left[u] = newnode();
			u = Left[u];
		} else if (s[i] == 'R') {
			if (!Right[u])
				Right[u] = newnode();
			u = Right[u];
		}
	}
	if (have_value[u])
		failed = true;
	value[u] = v;
	have_value[u] = true;
}

/* cpp */
bool read_input()
{
	string s;
	stringstream ss;
	int id;

	newtree(); failed = false;
	while (cin >> s) {
		if (s == "()")
			return true;
		ss.clear();	ss.str("");
		ss << s; ss.get();
		ss >> id; ss.get();
		ss >> s;
		addnode(id, s);
	}
	return false;
}
/* c */
// const int maxn = 1000;
// char s[maxn];
// bool read_input()
// {
// 	while (scanf("%s", s) == 1) {
// 		if (!strcmp(s, "()"))
// 			return true;
// 		int v;
// 		sscanf(s+1, "%d", &v);
// 		addnode(v, strchr(s, ',')+1);
// 	}
// 	return false;
// }
void bfs(vector<int>& ans)
{
	ans.clear();
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (Left[v]) q.push(Left[v]);
		if (Right[v]) q.push(Right[v]);
		if (!have_value[v]) failed = true;
		ans.push_back(value[v]);
	}
}
int main()
{
	vector<int> ans;
	while (read_input()) {
		bfs(ans);
		if (failed) printf("not complete\n");
		else {
		  for(int i = 0; i < ans.size(); i++) {
		    if(i != 0) printf(" ");
		    printf("%d", ans[i]);
		  }
		  printf("\n");
		}
	}
	return 0;
}
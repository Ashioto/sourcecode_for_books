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
void debug(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}
const int maxn = 10000+10;
int in_order[maxn], post_order[maxn], lch[maxn], rch[maxn], n;
bool read_list(int* a)
{
	string s;
	getline(cin, s);
	if (s == "") return false;
	stringstream ss(s);
	n = 0;
	int v;
	while (ss >> v) a[n++] = v;
	return true;
}

int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1 || L2 > R2) return 0; // empty tree
	int root = post_order[R2];
	int p = L1;
	while (in_order[p] != root) p++;
	int cnt = p - L1;
	lch[root] = build(L1, p-1, L2, L2+cnt-1);
	rch[root] = build(p+1, R1, L2+cnt, R2-1);
	return root;
}

int best, best_sum;
void dfs(int u, int sum) {
	sum += u;
	if (!lch[u] && !rch[u])
		if (sum < best_sum || (sum==best_sum && u < best)) {
			best = u; best_sum = sum;
		}
	if (lch[u]) dfs(lch[u], sum);
	if (rch[u]) dfs(rch[u], sum);
}

int main()
{
	while (read_list(in_order)) {
		read_list(post_order);
		build(0, n-1, 0, n-1);
		// debug(lch, n); debug(rch, n);
		best_sum = 1000000000;
		dfs(post_order[n-1], 0);
		cout << best << endl;
	}
	return 0;
}
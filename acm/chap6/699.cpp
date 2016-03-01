#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 10000;
int sum[maxn];

void build(int p)
{
	int v;
	cin >> v;
	if (v == -1) return;
	sum[p] += v;
	build(p-1);
	build(p+1);
}
bool init()
{
	int v;
	cin >> v;
	if (v == -1) return false;
	memset(sum, 0, sizeof(sum));
	int p = maxn / 2;
	sum[p] = v;
	build(p-1);
	build(p+1);
	return true;
}


int main()
{
	int kase = 0;
	while (init()) {
		int p = 0;
		while (!sum[p]) p++;
		cout << "Case " << ++kase << ":\n" << sum[p++];
		while (sum[p]) cout << " " << sum[p++];
		cout << "\n\n";
	}
	return 0;
}
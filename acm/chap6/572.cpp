#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

const int maxn = 100+5;

char pic[maxn][maxn];
int  m, n, flag[maxn][maxn];

void dfs(int r, int c, int id)
{
	flag[r][c] = id;
	for (int dr = -1; dr <= 1; dr++)
		for (int dc = -1; dc <= 1; dc++) {
			if (!dr && !dc)
				continue;
			int r2 = r + dr;
			int c2 = c + dc;
			if (r2 >= 0 && r2 < m && c2 >= 0 && c2 < n && (!flag[r2][c2]) && pic[r2][c2]=='@')
				dfs(r2, c2, id);
		}
}
int main()
{
	while (scanf("%d %d", &m, &n) == 2 && m) {
		for (int i = 0; i < m; i++) {
			scanf("%s", pic[i]);
		}
		memset(flag, 0, sizeof(flag));
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (pic[i][j] == '@' && !flag[i][j])
					dfs(i, j, ++cnt);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
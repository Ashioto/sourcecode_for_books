#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>
using namespace std;

struct Node
{
	int r, c, dir;
	Node(int r=0, int c=0, int dir=0):r(r), c(c), dir(dir) {}
};

const int maxn = 10;
Node p[maxn][maxn][4];

int  d[maxn][maxn][4], has_edge[maxn][maxn][4][3];
int  r0, c0, dir, r1, c1, r2, c2;

const char dirs[] = "NESW";
const char turns[] = "FLR";

const int  dr[] = {-1, 0, 1, 0};
const int  dc[] = {0, 1, 0, -1};

int dir_id(char ch)
{
	int pos = strchr(dirs, ch) - dirs;
	return pos;
}
int turn_id(char ch)
{
	return strchr(turns, ch) - turns;
}

bool read_case()
{
	char s[99], s2[99];
	if(scanf("%s%d%d%s%d%d", s, &r0, &c0, s2, &r2, &c2) != 6) return false;
	printf("%s\n", s);

	dir = dir_id(s2[0]);
	r1 = r0 + dr[dir];
	c1 = c0 + dc[dir];

	memset(has_edge, 0, sizeof(has_edge));
	for (;;) {
		int r, c;
		scanf("%d", &r);
		if (!r) break;
		scanf("%d", &c);
		while (scanf("%s", s)==1 && s[0]!='*') {
			for (int i = 1; i < strlen(s); i++) 
				has_edge[r][c][dir_id(s[0])][turn_id(s[i])] = 1;
		}
	}
	return true;
}


Node walk(Node &u, int turn)
{
	int dir = u.dir;
	if (turn == 1) dir = (dir+3) % 4;
	if (turn == 2) dir = (dir+1) % 4;
	return Node(u.r+dr[dir], u.c+dc[dir], dir);
}


bool inside(int r, int c)
{
	return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}


void print_ans(Node &u)
{
	vector<Node> nodes;
	for (;;) {
		nodes.push_back(u);
		if (d[u.r][u.c][u.dir] == 0)
			break;
		u = p[u.r][u.c][u.dir];
	}
	nodes.push_back(Node(r0, c0, dir));

	// 打印解，每行10个
	int cnt = 0;
	for(int i = nodes.size()-1; i >= 0; i--) {
	  if(cnt % 10 == 0) printf(" ");
	  printf(" (%d,%d)", nodes[i].r, nodes[i].c);
	  if(++cnt % 10 == 0) printf("\n");
	}
	if(nodes.size() % 10 != 0) printf("\n");
}
// void print_ans(Node u) {
//   // 从目标结点逆序追溯到初始结点
//   vector<Node> nodes;
//   for(;;) {
//     nodes.push_back(u);
//     if(d[u.r][u.c][u.dir] == 0) break;
//     u = p[u.r][u.c][u.dir];
//   }
//   nodes.push_back(Node(r0, c0, dir));

//   // 打印解，每行10个
//   int cnt = 0;
//   for(int i = nodes.size()-1; i >= 0; i--) {
//     if(cnt % 10 == 0) printf(" ");
//     printf(" (%d,%d)", nodes[i].r, nodes[i].c);
//     if(++cnt % 10 == 0) printf("\n");
//   }
//   if(nodes.size() % 10 != 0) printf("\n");
// }

void solve()
{
	memset(d, -1, sizeof(d));
	queue<Node> q;
	Node u = Node(r1, c1, dir);
	d[u.r][u.c][u.dir] = 0;
	q.push(u);
	while (!q.empty()) {
		Node u = q.front(); q.pop();
		if (u.r == r2 && u.c == c2) { print_ans(u); return; }
		for (int i = 0; i < 3; i++) {
			Node v = walk(u, i);
			if (inside(v.r, v.c) && d[v.r][v.c][v.dir]==-1 && has_edge[u.r][u.c][u.dir][i]) {
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	printf("  No Solution Possible\n");
}


int main()
{
	while (read_case())
		solve();
	return 0;
}

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

const int len = 32;
const int maxn = 1024 + 10;
int buf[len][len], cnt;

void draw(int r, int c, int w)
{
	char ch;
	cin >> ch;
	if (ch == 'p') {
		draw(r,     c+w/2, w/2);
		draw(r,     c,     w/2);
		draw(r+w/2, c,     w/2);
		draw(r+w/2, c+w/2, w/2);
	} else if (ch == 'f') {
		for (int i = r; i < r+w; i++)
			for (int j = c; j < c+w; j++)
				if (!buf[i][j]) {buf[i][j] = 1; cnt++;}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		memset(buf, 0, sizeof(buf));
		cnt = 0;
		draw(0, 0, len);
		draw(0, 0, len);
		printf("There are %d black pixels.\n", cnt);
	}
	return 0;
}
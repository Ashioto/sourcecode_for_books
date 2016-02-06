/** 这一道题挺坑的，只有百分之8左右的成功率
 *  有几个点记一下，一个是逻辑那里，找到可用的方向，正确的逻辑应该是有棋子并且是自己的，需要用最强的逻辑才行，例如W-BB？，？那里不可以放W
 *  第二个是格式，应该用%3d才行
 *  第三个是做的时候的读题，题目有说No legal move. 我一开始没看到
 *  */
#include<stdio.h>
char mat[8][10];
char flag;
typedef struct 
{
	int x;
	int y;
} point;
point direct[8] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
int is_in_mat(int x, int y)
{
	if (x < 0)
		return 0;
	if (x >= 8)
		return 0;
	if (y < 0)
		return 0;
	if (y >= 8)
		return 0;
	return 1;
}
int is_in_mat_and_has_chess(int x, int y)
{
	if (x < 0)
		return 0;
	if (x >= 8)
		return 0;
	if (y < 0)
		return 0;
	if (y >= 8)
		return 0;
	if (mat[x][y] == '-')
		return 0;
	return 1;
}
char reverse(char c)
{
	if (c == 'W')
		return 'B';
	else if (c == 'B')
		return 'W';
}


void list()
{
	int i, j, k;
	int count, _flag, _first = 1;
	int FLAG = 0;
	// for 64 positions
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (mat[i][j] != '-')
				continue;
			// for 8 directions
			_flag = 0;
			for (k = 0; k < 8; k++) {
				count = 2;
				int next_x = i+direct[k].x;
				int next_y = j+direct[k].y;
				// only if the next is other's chess
				if (is_in_mat(next_x, next_y) && mat[next_x][next_y]==reverse(flag)) {
					while (is_in_mat_and_has_chess(i+count*direct[k].x, j+count*direct[k].y)) {
						if (mat[i+count*direct[k].x][j+count*direct[k].y] == flag) {
							_flag = 1;
							break;
						}
						count++;
					}
				}
			}
			// if this direction is valid
			if (_flag) {
				if (_first)
					_first = 0;
				else
					printf(" ");
				printf("(%d,%d)", i+1, j+1);
				FLAG = 1;
			}
		}
	}
	if (!FLAG) {
		printf("No legal move.\n");
		flag = reverse(flag);
	} else {
		printf("\n");
	}
}
void move(char *s)
{
	int x = s[1] - '0' - 1;
	int y = s[2] - '0' - 1;
	mat[x][y] = flag;
	int i, j, k, count;

	for (k = 0; k < 8; k++) {
		count = 2;
		int next_x = x+direct[k].x;
		int next_y = y+direct[k].y;
		// only if the next is other's chess
		if (is_in_mat(next_x, next_y) && mat[next_x][next_y]==reverse(flag)) {
			while (is_in_mat_and_has_chess(x+count*direct[k].x, y+count*direct[k].y)) {
				if (mat[x+count*direct[k].x][y+count*direct[k].y] == flag) {
					for (i = 1; i < count; i++) {
						mat[x+i*direct[k].x][y+i*direct[k].y] = flag;
					}
					break;
				}
				count++;
			}
		}
	}

	int sum_w = 0, sum_b = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (mat[i][j] == 'W') 
				sum_w++;
			else if (mat[i][j] == 'B')
				sum_b++;
		}
	}

	// // for debug
	// for (i = 0; i < 8; i++) {
	// 	for (j = 0; j < 8; j++) {
	// 		printf("%c", mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");

	printf("Black -%3d White -%3d\n", sum_b, sum_w);

	flag = reverse(flag);
}
int main()
{
	int T;
	int first = 1;
	int i, j, k;
	char cmd[8];
	scanf("%d", &T);
	// printf("%d\n", direct[0].y);
	while (T--) {
		if (first)
			first = 0;
		else
			printf("\n");
		// init the matrix
		for (i = 0; i < 8; i++) 
			scanf("%s", mat[i]);
		scanf("%s", cmd);
		flag = cmd[0];

		// message loop
		while (scanf("%s", cmd) && cmd[0]!='Q') {
			if (cmd[0] == 'L')
				list();
			else if (cmd[0] == 'M')
				move(cmd);
		}

		// print matrix
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				printf("%c", mat[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

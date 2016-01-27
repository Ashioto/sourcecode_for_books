// #define LOCAL
#include<stdio.h>
#define INF 1000000

int main()
{
	#ifdef LOCAL
	  freopen("data.in", "r", stdin);
	  freopen("data.out", "w", stdout);
	#endif
	int  x, n = 0, min = INF, max = -INF, s = 0;

	while (scanf("%d", &x) == 1) {
		s += x;
		if (x < min) {
			min = x;
		}
		if (x > max) {
			max = x;
		}
		n++;
		printf("n is %d.\n", n);
	}

	printf("max,min,mean is %d,%d,%f", max, min, (double)s/n);
	return 0;
}

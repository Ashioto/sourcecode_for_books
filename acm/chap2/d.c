#define LOCAL
#include<stdio.h>
#define INF 1000000
int main()
{
	#ifdef LOCAL
	  freopen("data.in","r",stdin);
	  freopen("data.out","w",stdout);
	#endif
	int max = -INF, min = INF, s = 0, kase = 0, n, x;
	while (scanf("%d", &n) == 1 && n) {
		s   =  0;
		max = -INF;
		min =  INF;
		// printf("n is %d\n", n);
		int i;
		for (i = 0; i < n; i++) {
			scanf("%d", &x);
			if (x < min) min = x;
			if (x > max) max = x;
			s += x;
		}
		if (kase) printf("\n");
		printf("Case %d: %d %d %.3f", ++kase, min, max, (double)s / n);
	}

	return 0;
}
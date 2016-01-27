#include<stdio.h>
int main()
{
	int m, n, kase;
	double sum;
	while (scanf("%d%d", &m, &n) == 2 && (m || n)) {
		sum = 0;

		int i = 0;
		for (i = m; i <= n; i++) {
			double tmp = 1.0 / (i * i);
			sum += tmp;
			printf("%d\n", i*i);
		}

		printf("Case %d: %.5f\n", ++kase, sum);
	}

	return 0;
}
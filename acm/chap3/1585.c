#include<stdio.h>
#include<string.h>
int main()
{
	int T, tot;
	char s[88];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		int i;
		int w; /* w means weight of each O */

		w = 1;
		tot = 0;
		for (i = 0; i < n; i++) {
			if (s[i] == 'X') {
				w = 1;
				continue;
			}
			if (s[i] == 'O') {
				tot += w;
				w++;
			}
		}
		printf("%d\n", tot);
	}

	return 0;
}
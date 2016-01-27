#include<stdio.h>
#include<string.h>
char s[52][1002];
char words[] = {'T','G','C','A'};

int main()
{
    int T, m, n, tot;
    scanf("%d", &T);
    while (T--) {

        scanf("%d%d",&m,&n);
        int i = 0;
        for (i = 0; i < m; i++) {
            scanf("%s", s[i]);
        }

        tot = 0;
        for (i = 0; i < n; i++) {

            int j = 0;
            int counts[4];
            memset(counts, 0, sizeof(counts));
            for (j = 0; j < m; j++) {   /* count the num of a,t,g,c */
                if (s[j][i] == 'T') counts[0]++;
                if (s[j][i] == 'G') counts[1]++;
                if (s[j][i] == 'C') counts[2]++;
                if (s[j][i] == 'A') counts[3]++;
            }

            int max = -1, index = -1;
            int k = 0;
            for (k = 0; k < 4; k++) {
                if (counts[k] >= max) {
                    max = counts[k];
                    index = k;
                }
            }
            //result[i] = words[k];
            putchar(words[index]);

            for (k = 0; k < 4; k++) {
                if (k != index)
                    tot += counts[k];
            }
        }
        printf("\n");
        printf("%d", tot);
        printf("\n");
    }

    return 0;
}

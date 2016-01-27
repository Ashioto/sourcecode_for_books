#include <stdio.h>
#include <string.h>
int used[3003], x[3003], y[3003];
int main()
{
    int m, n;
    int count = 0;
    int first_num;
    while (scanf("%d%d", &m, &n) == 2) {
        first_num = m;
        memset(used, 0 ,sizeof(used));
        count = 0;
        x[count++] = m / n;
        m = m % n;
        int i, j, k;
        while (m && !used[m]) {
            y[count] = m;
            used[m] = count;
            x[count++] = 10 * m / n;
            m = 10 * m % n;
        }

        printf("%d/%d = %d", first_num, n, x[0]);
        printf(".");

        for (i = 1; i<=50 && i<count; i++) {
            if (m && y[i] == m) printf("(");
            printf("%d", x[i]);
        }

        if (!m) printf("(0");
        if (count > 50) printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", !m?1:count-used[m]);
    }

    return  0;
}
#include <stdio.h>
#include <string.h>
char s_a[103];
char s_b[103];
int a[210];
int b[210];
int min(int a, int b)
{
    return a<b ? a : b;
}
int max(int a, int b)
{
    return a>b ? a : b;
}
int main()
{
    int len_a, len_b;
    int i, j, k;
    int bias;
    while (scanf("%s", s_a)==1) {
        scanf("%s", s_b);
        len_a = (int)strlen(s_a);
        len_b = (int)strlen(s_b);
        for (i = 0; i < len_a; i++) {
            a[i] = s_a[i] - '0';
        }
        for (i = 0; i < len_b; i++) {
            b[i] = s_b[i] - '0';
        }

        int min_num = 100000;
        int length;
        for (bias = len_b; bias >= -len_a; bias--) {
            int flag = 1;
            for (i = 0; i < len_a; i++) {
                if (i+bias>=0 && i+bias<len_b) {
                    if (a[i]+b[i+bias] > 3)
                        flag = 0;
                }
            }
            if (flag) {
                int l = min(0, 0-bias);
                int r = max(len_a-1, len_b-1-bias);
                length = r - l + 1;
                min_num = min(min_num, length);
            }
        }
        printf("%d\n", min_num);

    }
    return 0;
}
#include<stdio.h>
#include<string.h>
char s[90];
int main()
{
    int i = 0;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int len = (int)strlen(s);
        for (i = 1; i < len; i++) {
            if (len%i != 0)
                continue;
            int j = 0;
            int flag = 1;
            int step;
            for (j = 0; j < i; j++) {
                step = 0;
                while (j+step < len) {
                    if (s[j] != s[j+step])
                        flag = 0;
                    step += i;
                }
            }
            if (flag)
                break;

        }
        printf("%d\n", i);
        if (T!=0)
            printf("\n");
    }

    return 0;
}
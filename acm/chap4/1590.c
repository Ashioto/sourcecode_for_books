#include<stdio.h>
#include<string.h>
int ip[1003][32];
void resolver(char *s, int *ip) 
{
    int nums[4], num = 0;
    int i, j = 3;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == '.') {
            nums[j] = num;
            j--;
            num = 0;
        } else {
            num = num * 10 + s[i] - '0';
        }
    }
    nums[j] = num;
    // printf("%d.%d.%d.%d\n", nums[0], nums[1], nums[2], nums[3]);
    for (i = 0; i < 32; i++) {
        if (nums[i / 8] & (1<<(i%8))) 
            ip[i] = 1;
        else
            ip[i] = 0;
        // if (i%8 == 0)
        //  printf("\n");
        // printf("%d", ip[i]);

    }
}


int main()
{
    int T, first = 1;
    int T_copy;
    while (scanf("%d", &T)==1) {
        T_copy = T;

        int max_num = -1;
        while (T--) {
            char s[20];
            scanf("%s", s);
            resolver(s, ip[T]);
        }
        int mask[32], addr[32];
        memset(addr, 0, sizeof(addr));
        int i, j, is_same = 1;
        float pos = 0;//TODO:明确好pos的含义，在本例中为变与不变之间的点，注意float
        for (i = 31; i >= 0; i--) {
            int tmp = ip[0][i];
            int flag = 1;
            for (j = 0; j < T_copy; j++) {
                if (tmp != ip[j][i]) {
                    flag = 0;   //TODO: 想错了，当时，不是每一个都会break的
                    is_same = 0;
                    pos = (float)i + 0.5;
                    break;
                }

            }
            if (flag)
                addr[i] = ip[0][i];
            if (is_same == 0)
                break;
        }
        // printf("pos is: %d\n", pos);
        for (i = 0; i < 32; i++) {
            if (i >= pos)
                mask[i] = 1;
            else 
                mask[i] = 0;
            // printf("%d", mask[i]);
        }
        int num = 0;
        for (i = 0; i < 32; i++) {
            num = num * 2 + addr[31-i];
            if ((i+1)%8 == 0) {
                printf("%d", num);
                if ((i+1) != 32)
                    printf(".");
                num = 0;
            }
        }
        printf("\n");
        num = 0;
        for (i = 0; i < 32; i++) {
            num = num * 2 + mask[31-i];
            if ((i+1)%8 == 0) {
                printf("%d", num);
                if ((i+1) != 32)
                    printf(".");
                num = 0;
            }
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
int nums[12];
int uniq[12];
int main()
{
    int i, j, k;
    int count = 0;
    int first = 1;
    int flag = 1;
    while (scanf("%d", &nums[0]) == 1) {
        for (i = 1; i < 12; i++) {
            scanf("%d", &nums[i]);
        }

        // uniq the nums array
        count = 0;
        uniq[count++] = nums[0];
        for (i = 1; i < 12; i++) {
            for (j = 0; j < count; j++) {
                if (nums[i] == uniq[j])
                    break;
            }
            if (j == count)
                uniq[count++] = nums[i];
        }

        if (count > 3) {
            printf("IMPOSSIBLE\n");
            continue;
        }

        if (count == 1) {
            printf("POSSIBLE\n");
            continue;
        }

        if (count == 2) {
            int _count = 0;
            for (i = 0; i < 12; i++) {
                if (nums[i] == uniq[0])
                    _count++;
            }
            if (_count!=4 && _count!=8) {
                printf("IMPOSSIBLE\n");
                continue;
            }
            int target = _count==8 ? uniq[0] : uniq[1];
            _count = 0;
            for (i = 0; i< 12; i+=2) {
                if (nums[i]==target && nums[i]==nums[i+1])
                    _count++;
            }
            if (_count != 2){
                printf("IMPOSSIBLE\n");
                continue;
            } else {
                printf("POSSIBLE\n");
                continue;
            }

        }


        flag = 1;
        int __count = 0;
        for (i = 0; i < 12; i+=2) {
            if (nums[i] == nums[i+1])
                __count++;
        }
        if (__count)
            flag = 0;
        for (i = 0; i < 3; i++) {
            __count = 0;
            for (j = 0; j < 12; j++) {
                if (uniq[i] == nums[j])
                    __count++;
            }
            if (__count != 4)
                flag = 0;
        }
        if (flag)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }

    return 0;
}
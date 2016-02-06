//在第几个block是校验block的判断上出了问题，%（i+1）必然不是按i为周期的
#include<stdio.h>
#include<string.h>
char data[6][6500];
int fix(int d, int s, int b, char *parity)
{
    int i, j, k;
    int count, index, sum;
    for (i = 0; i < s*b; i++) {
        sum = 0;
        count = 0;
        for (j = 0; j < d; j++) {
            if (data[j][i] == 'x') count++, index = j;
            if (data[j][i] == '1') sum++;
        }
        if (count >= 2)
            return 0;
        else if (count == 1) {
            if (parity[0] == 'E')
                if (sum % 2 == 1)
                    data[index][i] = '1';
                else
                    data[index][i] = '0';
            else
                if (sum % 2 == 1)
                    data[index][i] = '0';
                else
                    data[index][i] = '1';
        } else if (count == 0) {
            sum %= 2;
            if (parity[0] == 'E' &&  sum) return 0;
            if (parity[0] == 'O' && !sum) return 0;
        }
    }
    return 1;
}
void output_data(int d, int s, int b){
    int i, j, k;
    int number = 0;
    int bit_count = 0;
    int block_count = 0;
    int valid_block = 0;
    for (i = 0; i < s*b; i += s) {
        for (j = 0; j < d; j++) {
            block_count++;
            if (block_count % (d+1) == 1) {
                // printf("block_count: %d\n", block_count);
                if (block_count == d*d)
                    block_count = 0;
                continue;
            }
            valid_block++;
            // printf("valid_block: %d\n", valid_block);
            for (k = 0; k < s; k++) {
                bit_count = (bit_count+1) % 4;
                number = number*2 + data[j][i+k] - '0';
                // printf("%d,", number);
                if (!bit_count) {
                    printf("%X", number);
                    number = 0;
                }
            }
        }
    }
    if (bit_count) {
        while (bit_count < 4) {
            bit_count++;
            number = number * 2;
        }
        printf("%X", number);
    }
    // printf("block_count: %d\n", block_count);
    // printf("valid_block: %d\n", valid_block);
    printf("\n");




        // int sum=0,bit_cnt=0;
        // for(int i=0;i<b;++i){
        //     int except =i%d;
        //     for(int j=0;j<d;j++){
        //         if(j==except) continue;
        //         for(int k=i*s;k<i*s+s;++k){
        //             bit_cnt=(bit_cnt+1)%4;
        //             if(data[j][k]=='0') sum*=2;
        //             else sum=sum*2+1;
        //             if(!bit_cnt){
        //                 printf("%X",sum);
        //                 sum=0;
        //             }
        //         }
        //     }
        // }
        // if(bit_cnt){
        //     int over =4-bit_cnt;
        //     sum=sum*(1<<over);
        //     printf("%X",sum);
        // }
        // printf("\n");
    
}
int main()
{
    int kase = 0, d, s, b;
    int i, j, k;
    char parity[3];
    while (scanf("%d", &d)==1 && d) {
        scanf("%d%d", &s, &b);
        scanf("%s", parity);
        for (i = 0; i < d; i++) {
            scanf("%s", data[i]);
        }
        // printf("%d,%d,%d\n%s,%s\n",d,s,b,parity,data[0]);
        // printf("%d\n", fix(d,s,b,parity));
        if (!fix(d, s, b, parity)) 
            printf("Disk set %d is invalid.\n", ++kase);
        else {
            printf("Disk set %d is valid, contents are: ", ++kase);
            output_data(d, s, b);
        }
        // for (i = 0; i < d; i++) {
        //     for (j = 0; j < s*b; j++)
        //         printf("%c", data[i][j]);
        //     printf("\n");
        // }
    }
    return 0;
}

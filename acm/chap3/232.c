#include <stdio.h>
#include <string.h>
char puzzle[13][13];
int info[13][13];
int is_start(int i, int j)
{
    if (puzzle[i][j]!='*' && (i-1<0 || j-1<0 || puzzle[i-1][j]=='*' || puzzle[i][j-1]=='*'))
        return 1;
    else
        return 0;
}
void print_puzzle(int m, int n)
{
    printf("The puzzle is :\n");
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ",puzzle[i][j]);
        }
        printf("\n");
    }
}
void print_info(int m, int n)
{
    printf("The info matrix is :\n");
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ",info[i][j]);
        }
        printf("\n");
    }
}
void invert_puzzle(int m, int n){
    char tmp[13][13];
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            tmp[i][j] = puzzle[j][i];
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            puzzle[i][j] = tmp[i][j];
        }
    }
}
int main()
{
    int m, n;
    int i, j, k;
    int flag;
    int kase = 0;
    int first = 1;
    while (scanf("%d", &m)) {
        if (m == 0)
            break;
        scanf("%d", &n);
        if (first)
            first = 0;
        else
            printf("\n");
        printf("puzzle #%d:\n", ++kase);
        // clear matrix info to ZERO
        for (i = 0; i < 13; i++) {
            for (j = 0; j < 13; j++) {
                info[i][j] = 0;
            }
        }
        // read the PUZZLE
        for (i = 0; i < m; i++) {
            scanf("%s", puzzle[i]);
        }
        // generate the info matrix
        int count = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (is_start(i, j))
                    info[i][j] = ++count;
                else
                    info[i][j] = 0;
                if (puzzle[i][j] == '*')
                    info[i][j] = -1;
            }
        }

        // for DEBUG
        //print_puzzle(m, n);
        //print_info(m, n);

        // 1st
        printf("Across\n");
        flag = 0;
        for (i = 0; i < m; i++) {
            if (flag) {
                flag = 0;
                printf("\n");
            }
            for (j = 0; j < n; j++) {
                if (!flag) {
                    if (info[i][j] > 0) {// is a start point
                        printf("%3d.%c", info[i][j],puzzle[i][j]);
                        flag = 1;
                    }
                } else {
                    if (info[i][j] != -1)
                        printf("%c", puzzle[i][j]);
                    else {
                        printf("\n");
                        flag = 0;
                    }
                }
            }
        }
        if (flag)
            printf("\n");

        //invert_puzzle(m, n);

        // 2nd
        printf("Down\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if(info[i][j] > 0) {
                    k = i;
                    printf("%3d.", info[i][j]);
                    while (k<m && info[k][j]>=0) {
                        printf("%c", puzzle[k][j]);
                        info[k][j] = -1;
                        k++;
                    }
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
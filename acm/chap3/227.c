#include <stdio.h>
#include <string.h>
char map[5][8];
char cmd[1002];
int kase = 0;
void print_map();
void create_map()
{
    int i = 1;
    for (i = 1; i < 5; i++) {
        fgets(map[i], 8, stdin);
    }
    for (i = 0; i <5; i++) {
        if (map[i][4] == '\n') {
            map[i][4] = ' ';
            map[i][5] = '\0';
        }
    }
    //printf("in create map function\n");
    //print_map();
}
int execute(char *cmd, int start, int stop)
{
    //printf("cmd is %s\n", cmd);
    int is_valid = 1;
    int blank_i, blank_j;
    int i, j;
    // find where the space is
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (map[i][j] == ' ') {
                blank_i = i;
                blank_j = j;
            }
        }
    }
   // printf("blank is %d,%d\n",blank_i,blank_j);

    for (i = start; i <= stop; i++) {
        switch (cmd[i]) {
            case 'A':
                if (blank_i-1 >= 0) {
                    map[blank_i][blank_j] = map[blank_i-1][blank_j];
                    blank_i--;
                    map[blank_i][blank_j] = ' ';
                } else
                    is_valid = 0;
                break;
            case 'B':
                if (blank_i+1 < 5) {
                    map[blank_i][blank_j] = map[blank_i+1][blank_j];
                    blank_i++;
                    map[blank_i][blank_j] = ' ';
                } else
                    is_valid = 0;
                break;
            case 'L':
                if (blank_j-1 >= 0) {
                    map[blank_i][blank_j] = map[blank_i][blank_j-1];
                    blank_j--;
                    map[blank_i][blank_j] = ' ';
                } else
                    is_valid = 0;
                break;
            case 'R':
                if (blank_j+1 < 5) {
                    map[blank_i][blank_j] = map[blank_i][blank_j+1];
                    blank_j++;
                    map[blank_i][blank_j] = ' ';
                } else
                    is_valid = 0;
                break;
            default:
                is_valid = 0;
                break;
        }
        if (!is_valid)
            return is_valid;
    }

    return  is_valid;
}
void print_map()
{
    printf("Puzzle #%d:\n", ++kase);
    int i, j;
    // find where the space is
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("%c ",map[i][j]);
        }
        printf("%c\n", map[i][4]);
    }
}
int main()
{
    int flag = 1;
    int len;
    int first = 1;
    while (fgets(map[0], 8, stdin)) {
        flag = 1;
        if (map[0][0] == 'Z')
            break;
        if (first) {
            first = 0;
        } else 
            printf("\n");

        create_map();
        do {
            scanf("%s", cmd);
            int stop;
            len = (int) strlen(cmd);
            if (cmd[len-1] != '0')
                stop = len - 1;
            else
                stop = len - 2;

            if (!execute(cmd, 0, stop))
                flag = 0;
        } while (cmd[len-1] != '0');

        if (flag)
            print_map();
        else {
            printf("Puzzle #%d:\n", ++kase);
            printf("This puzzle has no final configuration.\n");
        }
        getchar();
    }
}
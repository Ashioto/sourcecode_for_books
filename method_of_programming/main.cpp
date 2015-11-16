#include <stdio.h>

void ReverseString(char *s, int from, int to) {
    char t;
    while (from < to) {
        t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void ReverseWord(char *s, int n) {
    int t1 = 0, t2 = 0;
    while (t2 < n) {
        while (t2 < n && s[t2] != ' ')
            t2++;
        ReverseString(s, t1, t2 - 1);
        t1 = ++t2;
    }
    ReverseString(s, 0, n - 1);
}

int main() {
    char str[] = "I am a student.";
    char *s = str;
    ReverseWord(s, 15);
    printf("%s", s);
    return 0;
}

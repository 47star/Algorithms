#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

char b[9][9];

inline bool check(char r, char c) {
    for (char i = 0; i < 9; i++) {
        if (i != c && b[r][c] == b[r][i] || i != r && b[r][c] == b[i][c])
            return false;
    }

    char ar = r / 3 * 3;
    char ac = c / 3 * 3;

    for (char i = ar; i < ar + 3; i++)
        for (char j = ac; j < ac + 3; j++) {
            if (i == r && j == c)
                continue;
            if (b[r][c] == b[i][j])
                return false;
        }

    return true;
}

void dfs(char r, char c) {
    if (r == 9) {
        for (char i = 0; i < 9; i++) {
            for (char j = 0; j < 9; j++)
                printf("%hhd", b[i][j]);
            printf("\n");
        }
        exit(0);
    }

    if (c == 9) {
        dfs(r + 1, 0);
        return;
    }

    if (b[r][c] == 0) {
        for (char i = 1; i < 10; i++) {
            b[r][c] = i;
            if (check(r, c))
                dfs(r, c + 1);
        }
        b[r][c] = 0;
    } else
        dfs(r, c + 1);
}

int main() {
    memset(b, 0, sizeof(char) * 81);

    char *l = (char*)malloc(9);
    
    for (char i = 0; i < 9; i++) {
        scanf("%s", l);
        for (char j = 0; j < 9; j++)
            b[i][j] = l[j] - '0';
    }
    
    dfs(0, 0);

    return 0;
}
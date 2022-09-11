#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

char m[3072][6143];

void render(int r, int c) {
    m[r][c] = m[r + 1][c - 1] = m[r + 1][c + 1] = m[r + 2][c - 2] = m[r + 2][c - 1] = m[r + 2][c] = m[r + 2][c + 1] = m[r + 2][c + 2] = '*';
}

void s(int l, int r, int c) {
    if (l == 3) {
        render(r, c);
        return;
    }

    l /= 2;
    s(l, r, c);
    s(l, r + l, c - l);
    s(l, r + l, c + l);
}

int main() {
    int n, i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n * 2 - 1; j++)
            m[i][j] = ' ';

    s(n, 0, n - 1);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n * 2 - 1; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }

    return 0;
}
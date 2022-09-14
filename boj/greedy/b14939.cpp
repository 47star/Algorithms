#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool b[10][10], bt[10][10];

void t(int x, int y) {
    bt[x][y] = !bt[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (-1 < nx && nx < 10 && -1 < ny && ny < 10)
            bt[nx][ny] = !bt[nx][ny];
    }
}

bool off() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (bt[i][j])
                return false;
    return true;
}

int main() {
    char a;
    int i, j, k, c, m = 2147483647;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            scanf("%c", &a);
            b[i][j] = a == 'O';
        }
        scanf("%c", &a);
    }

    for (i = 0; i < 1 << 10; i++) {
        c = 0;
        
        for (j = 0; j < 10; j++)
            for (k = 0; k < 10; k++)
                bt[j][k] = b[j][k];

        for (j = 0; j < 10; j++)
            if (i & (1 << j)) {
                t(0, j);
                c++;
            }
        
        for (j = 1; j < 10; j++)
            for (k = 0; k < 10; k++)
                if (bt[j - 1][k]) {
                    t(j, k);
                    c++;
                }

        if (off() && c < m) {
            m = c;
        }
    }

    printf("%d", m == 2147483647 ? -1 : m);

    return 0;
}
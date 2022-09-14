#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int r, c, l = 1 << 31;
char m[21][21];
bool v[26];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y, int d) {
    int nx, ny;
    bool vi = false;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (-1 < nx && nx < r && -1 < ny && ny < c && !v[m[nx][ny] - 'A']) {
            vi = true;
            v[m[nx][ny] - 'A'] = true;
            dfs(nx, ny, d + 1);
            v[m[nx][ny] - 'A'] = false;
        }
    }
    if (!vi && l < d)
        l = d;
}

int main() {
    memset(v, 0, sizeof(v));

    char n;
    int i, j;
    scanf("%d %d", &r, &c);

    for (i = 0; i < r; i++) {
        scanf("%c", &n);
        for (j = 0; j < c; j++)
            scanf("%c", &m[i][j]);
    }

    v[m[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    printf("%d", l);

    return 0;
}
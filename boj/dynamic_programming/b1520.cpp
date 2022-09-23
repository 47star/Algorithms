#include <bits/stdc++.h>

using namespace std;

int a, b, i, j, m[500][500], dp[500][500];

char dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 };

int dfs(int x, int y) {
    if (x == a - 1 && y == b - 1)
        return 1;

    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (-1 < nx && nx < a && -1 < ny && ny < b && m[nx][ny] < m[x][y])
            dp[x][y] += dfs(nx, ny);
    }

    return dp[x][y];
}

int main() {
    memset(dp, -1, sizeof dp);

    cin >> a >> b;

    for (i = 0; i < a; i++)
        for (j = 0; j < b; j++)
            cin >> m[i][j];

    cout << dfs(0, 0);

    return 0;
}
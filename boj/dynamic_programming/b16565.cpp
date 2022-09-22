#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define MOD 10007

using namespace std;

int main() {
    int i, j, n, dp[53][53], a = 0;

    scanf("%d", &n);

    for (i = 0; i < 53; i++) {
        dp[i][0] = dp[i][i] = 1;
        for (j = 1; j < i; j++)
            dp[i][i - j] = (dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD);
    }

    for (i = 4; i < n + 1; i += 4) {
        if ((i / 4) % 2 == 0)
            a -= dp[13][i / 4] * dp[52 - i][n - i];
        else
            a += dp[13][i / 4] * dp[52 - i][n - i];
        a %= MOD;
    }

    if (a < 0)
        a += MOD;
    
    cout << a;

    return 0;
}
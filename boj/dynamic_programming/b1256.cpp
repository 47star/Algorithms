#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int i, j, n, m, k, dp[201][101], f;
    scanf("%d %d %d", &n, &m, &k);
    f = n + m;
    k--;

    dp[0][0] = 1;
    for (i = 0; i <= f; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (j = 1; j < i && j <= m; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            if (1000000000 < dp[i][j])
                dp[i][j] = 1000000000;
        }
    }

    if (dp[f][m] <= k) {
        printf("-1");
        return 0;
    }

    for (i = f - 1; 0 <= i; i--) {
        if (m <= i && k < dp[i][m])
            printf("a");
        else {
            printf("z");
            k -= dp[i][m--];
        }
    }

    return 0;
}
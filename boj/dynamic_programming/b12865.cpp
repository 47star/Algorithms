#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, i, j, w[101], v[101], dp[101][100001];
    scanf("%d %d", &n, &k);

    for (i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &v[i]);
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= k; j++)
            if (w[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
    
    printf("%d", dp[n][k]);

    return 0;
}
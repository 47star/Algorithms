#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, l, a, b, c;
long long i, dp[32][32], pb[32][32];

long long bino(int n, int r) {
    if (n < r || n < 0 || r < 0)
        return 0;
    return dp[n][r] == -1 ? dp[n][r] = bino(n - 1, r) + bino(n - 1, r - 1) : dp[n][r];
}

int main() {
    scanf("%d %d %lld", &n, &l, &i);

    memset(dp, -1, sizeof dp);
    dp[0][0] = dp[1][0] = dp[1][1] = 1;

    for (a = 0; a <= n; a++)
        for (b = 0; b < 32; b++)
            for (c = 0; c <= b; c++)
                pb[a][b] += bino(a, c);
    
    for (a = n; 1 <= a; a--) {
        if (!l)
            printf("0");
        else if (pb[a - 1][l] < i) {
            printf("1");
            i -= pb[a - 1][l--];
        } else
            printf("0");
    }

    return 0;
}
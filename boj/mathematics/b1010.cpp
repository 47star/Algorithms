#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int dp[30][30];

int c(unsigned char n, unsigned char r) {
    if (0 < dp[n][r])
        return dp[n][r];
    
    if (n == r || r == 0)
        return dp[n][r] = 1;
    
    return dp[n][r] = c(n - 1, r - 1) + c(n - 1, r);
}

int main() {
    unsigned int t, i;
    unsigned char n, r;

    scanf("%u", &t);

    for (i = 0; i < t; i++) {
        scanf("%hhu %hhu", &r, &n);
        printf("%u\n", c(n, r));
    }

    return 0;
}
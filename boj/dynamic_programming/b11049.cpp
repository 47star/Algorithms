#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m[501][2], dp[501][501], i, j, k;
    scanf("%d", &n);

	for (i = 1; i < n + 1; i++)
		scanf("%d %d", &m[i][0], &m[i][1]);

	for (i = 1; i < n; i++)
		for (j = 1; i + j < n + 1; j++) {
			dp[j][i + j] = 1000000000;
			for (k = j; k < i + j + 1; k++)
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + m[j][0] * m[k][1] * m[i + j][1]);
		}

	printf("%d", dp[1][n]);
}

???
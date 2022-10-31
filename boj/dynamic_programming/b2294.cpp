#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int n, k, c[100], dp[100001], i, j;
    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++)
        scanf("%d", &c[i]);
    
    for (i = 1; i < k + 1; i++)
        dp[i] = 10001;

    for (i = 0; i < n; i++)
        for (j = c[i]; j < k + 1; j++)
            dp[j] = min(dp[j], dp[j - c[i]] + 1);
    
    printf("%d", dp[k] == 10001 ? -1 : dp[k]);

    return 0;
}
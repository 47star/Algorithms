#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int t, n, k, c[100], dp[10001], i, j;

    scanf("%d", &t);

    while (t--) {
        memset(dp, 0, sizeof(dp));
        
        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &c[i]);
        
        scanf("%d", &k);

        dp[0] = 1;
        for (i = 0; i < n; i++)
            for (j = c[i]; j < k + 1; j++)
                if (dp[j - c[i]])
                    dp[j] += dp[j - c[i]];
        
        printf("%d\n", dp[k]);
    }

    return 0;
}
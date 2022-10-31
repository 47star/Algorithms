#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int n, k, c[100], dp[100001] = { 0 }, i, j;
    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++)
        scanf("%d", &c[i]);

    dp[0] = 1;
    for (i = 0; i < n; i++)
        for (j = c[i]; j < k + 1; j++)
            if (dp[j - c[i]])
                dp[j] += dp[j - c[i]];
    
    printf("%d", dp[k]);

    return 0;
}
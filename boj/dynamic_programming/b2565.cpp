#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, dp[110];
pair<int, int> l[110];

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int i, j, c = 0;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d %d", &l[i].first, &l[i].second);
    
    sort(l + 1, l + n + 1, compare);
    for (i = 1; i <= n; i++) {
        dp[i] = 1;
        for (j = 1; j < i; j++)
            if (l[j].second < l[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        if (c < dp[i])
            c = dp[i];
    }

    printf("%d", n - c);

    return 0;
}
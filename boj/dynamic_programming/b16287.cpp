#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, n, a[5000], i, j, k;
    bool dp[400001] = { 0, };

    scanf("%d %d", &w, &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    sort(a, a + n);

    for (i = 0; i < n - 2; i++) {
        for (j = 0; j < i; j++)
            dp[a[i] + a[j]] = 1;

        for (j = i + 2; j < n; j++) {
            k = w - a[i + 1] - a[j];

            if (k < 0)
                break;

            if (400000 < k || !dp[k])
                continue;

            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}
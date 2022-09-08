#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int i, n, a[500001], b[8001] = { 0 }, m = 0, idx;
    double sum = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    sort(a, a + n);

    for (i = 0; i < n; i++) {
        idx = a[i] + 4000;
        b[idx]++;
        if (m < b[idx])
            m = b[idx];
    }

    printf("%d\n", (int)round(sum / n));

    printf("%d\n", a[n == 1 ? 0 : (n + 1) / 2 - 1]);

    for (i = 0, idx = 0, sum = 0; i < 8001; i++) {
        if (b[i] == 0)
            continue;
        if (b[i] == m)
            if (sum == 0) {
                idx = i;
                sum++;
            } else if (sum == 1) {
                idx = i;
                break;
            }
    }
    printf("%d\n", idx - 4000);
    
    printf("%d", a[n - 1] - a[0]);

    return 0;
}
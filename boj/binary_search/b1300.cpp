#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long n, k, i, count, low = 1, high, mid;

    scanf("%lu\n%lu", &n, &k);

    high = k;

    while (low < high) {
        mid = (low + high) >> 1;
        count = 0;

        for (i = 1; i <= n; i++)
            count += min(mid / i, n);

        if (k <= count)
            high = mid;
        else
            low = mid + 1;
    }

    printf("%lu", low);

    return 0;
}
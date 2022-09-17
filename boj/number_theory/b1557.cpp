#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long k, a[42000] = { 0 }, i, j, f = 0, l, m;
    memset(a, 0, sizeof(a));
    scanf("%lld", &k);

    a[1] = 1;
    for (i = 1; i <= 42000; i++)
        for (j = i + i; j <= 42000; j += i)
            a[j] -= a[i];
    
    l = k + k;
    while (f < l - 1) {
        m = (f + l) >> 1;
        for (i = 1, j = 0; i * i <= m; i++)
            j += a[i] * m / (i * i);
        if (j < k)
            f = m;
        else
            l = m;
    }

    printf("%lld", l);

    return 0;
}
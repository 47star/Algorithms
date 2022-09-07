#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long n, m, i, j;
    scanf("%lu %lu", &n, &m);

    bool p[1000001];
    memset(p, true, sizeof p);

    p[1] = false;

    for (i = 2; i * i <= m; i++) {
        if (p[i])
            for (j = i * i; j <= m; j += i)
                p[j] = false;
    }

    for (i = n; i <= m; i++)
        if (p[i])
            printf("%lu\n", i);

    return 0;
}
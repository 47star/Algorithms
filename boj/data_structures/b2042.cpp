#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

long long ar[1000001], t[1 << 21];

long long in(int n, int f, int l) {
    if (f == l)
        return t[n] = ar[f];

    int m = (f + l) >> 1;

    return t[n] = in(n + n, f, m) + in(n + n + 1, m + 1, l);
}

long long s(int n, int f, int l, int le, int ri) {
    if (l < le || ri < f)
        return 0;
    if (le <= f && l <= ri)
        return t[n];
    int m = (f + l) >> 1;
    return s(n + n, f, m, le, ri) + s(n + n + 1, m + 1, l, le, ri);
}

void u(int n, int f, int l, int i, long long d) {
    if (i < f || l < i)
        return;

    t[n] += d;

    if (f == l)
        return;

    int m = (f + l) >> 1;

    u(n + n, f, m, i, d);
    u(n + n + 1, m + 1, l, i, d);
}

int main() {
    int n, m, k, a, b, i;
    long long c, t;

    scanf("%d %d %d", &n, &m, &k);

    for (i = 0; i < n; i++)
        scanf("%lld", &ar[i]);
    
    in(1, 0, n - 1);

    for (i = 0; i < m + k; i++) {
        scanf("%d %d %lld", &a, &b, &c);

        if (a == 1) {
            t = c - ar[b - 1];
            ar[b - 1] = c;
            u(1, 0, n - 1, b - 1, t);
            continue;
        }

        printf("%lld\n", s(1, 0, n - 1, b - 1, c - 1));
    }

    return 0;
}
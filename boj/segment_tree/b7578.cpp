#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int n, a[1000001], b[500001];
vector<long long int> t;

long long int sum(int n, int f, int l, int le, int ri) {
    if (l < le || ri < f)
        return 0;
    if (le < f + 1 && l < ri + 1)
        return t[n];
    return sum(n * 2, f, (f + l) >> 1, le, ri) + sum(n * 2 + 1, ((f + l) >> 1) + 1, l, le, ri);
}

void update(int n, int f, int l, int i, int d) {
    if (i < f || l < i)
        return;

    t[n] += d;

    if (f ^ l) {
        update(n * 2, f, (f + l) >> 1, i, d);
        update(n * 2 + 1, ((f + l) >> 1) + 1, l, i, d);
    }
}

int main() {
    int i, j;
    long long int r = 0;

    scanf("%d", &n);

    t = vector<long long int>(1 << ((int)ceil(log2(n)) + 1));

    for (i = 1; i < n + 1; i++) {
        scanf("%d", &j);
        a[j] = i;
    }

    for (i = 1; i < n + 1; i++) {
        scanf("%d", &j);
        b[i] = a[j];
    }

    for (i = 1; i < n + 1; i++) {
        j = b[i];
        r += sum(1, 1, n, j + 1, n);
        update(1, 1, n, j, 1);
    }

    printf("%lld", r);

    return 0;
}
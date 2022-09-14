#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

long long p[44];
vector<long long> a, b;

void r(int f, int l, long long sum, vector<long long> &v) {
    if (f == l) {
        v.push_back(sum);
        return;
    }
    r(f + 1, l, sum + p[f], v);
    r(f + 1, l, sum, v);
}

int main() {
    long long n, s, i, f, l, u;
    scanf("%lld %lld", &n, &s);

    for (i = 0; i < n; i++)
        scanf("%lld", &p[i]);
    
    r(0, n / 2 + 1, 0, a);
    r(n / 2 + 1, n, 0, b);

    sort(b.begin(), b.end());

    f = 0;

    for (i = 0; i < a.size(); i++) {
        l = lower_bound(b.begin(), b.end(), s - a[i]) - b.begin();
        u = upper_bound(b.begin(), b.end(), s - a[i]) - b.begin();
        f += u - l;
    }

    if (s == 0)
        f--;

    printf("%lld", f);

    return 0;
}
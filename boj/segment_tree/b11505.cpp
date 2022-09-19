#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define M 1000000007;

using namespace std;

int n, m, k, a[1000001];
vector<long long int> t;

long long int init(int n, int f, int l) {
    return t[n] = f == l ? a[f] : init(n * 2, f, (f + l) >> 1) * init(n * 2 + 1, ((f + l) >> 1) + 1, l) % M;
}

long long update(int n, int i, long long v, int f, int l) {
    if (l < i || i < f)
        return t[n];
    else if (f == l)
        return t[n] = v;
    
    return t[n] = update(n * 2, i, v, f, (f + l) >> 1) * update(n * 2 + 1, i, v, ((f + l) >> 1) + 1, l) % M;
}

long long int multiply(int n, int f, int l, int le, int ri) {
    if (l < le || ri < f)
        return 1;
    else if (le < f + 1 && l < ri + 1)
        return t[n];
    
    return multiply(n * 2, f, (f + l) >> 1, le, ri) * multiply(n * 2 + 1, ((f + l) >> 1) + 1, l, le, ri) % M;
}

int main() {
    int x, y, z;

    scanf("%d %d %d", &n, &m, &k);
    m += k;

    t = vector<long long int>(1 << ((int)ceil(log2(n)) + 1));

    for (x = 1; x < n + 1; x++)
        scanf("%d", &a[x]);
    
    init(1, 0, n);

    while (m--) {
        scanf("%d %d %d", &x, &y, &z);
        
        if (x == 1) {
            a[y] = z;
            update(1, y, z, 0, n);
        } else {
            if (y < z)
                printf("%lld\n", multiply(1, 0, n, y, z));
            else
                printf("%lld\n", multiply(1, 0, n, z, y));
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int a[100000];

long dc2(int l, int m, int h) {
    int le = m, ri = m;
    long he = a[m], ma = he;

    while (l < le && ri < h) {
        he = a[le - 1] < a[ri + 1] ? min(he, (long)a[++ri]) : min(he, (long)a[--le]);
        ma = max(ma, he * (ri - le + 1));
    }

    while (ri < h) {
        he = min(he, (long)a[++ri]);
        ma = max(ma, he * (ri - le + 1));
    }

    while (l < le) {
        he = min(he, (long)a[--le]);
        ma = max(ma, he * (ri - le + 1));
    }

    return ma;
}

long dc(int l, int h) {
    if (l == h)
        return a[l];
    
    int m = (l + h) >> 1;

    return max(max(dc(l, m), dc(m + 1, h)), dc2(l, m, h));
}

int main() {
    int n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    printf("%ld\n", dc(0, n - 1));

    return 0;
}
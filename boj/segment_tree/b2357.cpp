#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int n, m, a[100001];
vector<int> mint, maxt;

void init(int n, int f, int l) {
    if (f == l) {
        mint[n] = maxt[n] = a[f];
        return;
    }

    init(n * 2, f, (f + l) >> 1);
    init(n * 2 + 1, ((f + l) >> 1) + 1, l);

    mint[n] = min(mint[n * 2], mint[n * 2 + 1]);
    maxt[n] = max(maxt[n * 2], maxt[n * 2 + 1]);
}

pair<int, int> find(int n, int f, int l, int le, int ri) {
    if (l < le || ri < f)
        return make_pair(INT32_MAX, 0);
    else if (le < f + 1 && l < ri + 1)
        return make_pair(mint[n], maxt[n]);
    
    pair<int, int> i = find(n * 2, f, (f + l) >> 1, le, ri), 
        j = find(n * 2 + 1, ((f + l) >> 1) + 1, l, le, ri);
    return make_pair(min(i.first, j.first), max(i.second, j.second));
}

int main() {
    int i, j;
    pair<int, int> r;
    scanf("%d %d", &n, &m);

    i = 1 << ((int)ceil(log2(n)) + 1);
    mint = vector<int>(i);
    maxt = vector<int>(i);

    for (i = 1; i < n + 1; i++)
        scanf("%d", &a[i]);

    init(1, 1, n);
    
    while (m--) {
        scanf("%d %d", &i, &j);
        r = find(1, 1, n, i, j);
        printf("%d %d\n", r.first, r.second);
    }

    return 0;
}
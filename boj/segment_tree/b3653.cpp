#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int n, m, t[800000];

int init(int n, int f, int l) {
    if (f == l)
        return t[n] = f < m ? 0 : 1;

    return t[n] = init(n * 2, f, (f + l) >> 1) + init(n * 2 + 1, ((f + l) >> 1) + 1, l);
}

int sum(int n, int f, int l, int le, int ri) {
    if (ri < f || l < le)
        return 0;
    
    if (le < f + 1 && l < ri + 1)
        return t[n];
    
    return sum(n * 2, f, (f + l) >> 1, le, ri) + sum(n * 2 + 1, ((f + l) >> 1) + 1, l, le, ri);
}

void update(int n, int i, int d, int f, int l) {
    if (i < f || l < i)
        return;

    t[n] += d;

    if (f == l)
        return;
    
    update(n * 2, i, d, f, (f + l) >> 1);
    update(n * 2 + 1, i, d, ((f + l) >> 1) + 1, l);
}

int main() {
    int c, i, v[100001], j, k;
    scanf("%d", &c);

    while (c--) {
        scanf("%d %d", &n, &m);

        for (i = 1; i < n + 1; i++)
            v[i] = i + m - 1;
        
        init(1, 0, n + m - 1);

        for (i = 0; i < m; i++) {
            scanf("%d", &j);

            printf("%d ", sum(1, 0, n + m - 1, 0, v[j] - 1));

            update(1, v[j], -1, 0, n + m - 1);
            update(1, m - i - 1, 1, 0, n + m - 1);
            
            v[j] = m - i - 1;
        }

        printf("\n");
    }

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int p[100000];

int find(int i) {
    return p[i] == i ? i : p[i] = find(p[i]);
}

int main() {
    int n, i, a, b, c, t = 0;
    pair<int, int> x[100000], y[100000], z[100000];
    pair<int, pair<int, int> > co[99999 * 3];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i;
        scanf("%d %d %d", &a, &b, &c);
        x[i] = { a, i };
        y[i] = { b, i };
        z[i] = { c, i };
    }
    
    sort(x, x + n);
    sort(y, y + n);
    sort(z, z + n);
    
    for (i = 0; i < n - 1; i++) {
        co[i] = { x[i + 1].first - x[i].first, { x[i].second, x[i + 1].second } };
        co[i + (n - 1)] = { y[i + 1].first - y[i].first, { y[i].second, y[i + 1].second } };
        co[i + (n - 1) * 2] = { z[i + 1].first - z[i].first, { z[i].second, z[i + 1].second } };
    }

    sort(co, co + (n - 1) * 3);

    for (i = 0; i < (n - 1) * 3; i++) {
        a = find(co[i].second.first);
        b = find(co[i].second.second);

        if (a != b) {
            if (a < b)
                p[b] = a;
            else
                p[a] = b;
            t += co[i].first;
        }
    }

    printf("%d", t);

    return 0;
}
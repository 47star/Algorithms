#include <bits/stdc++.h>

using namespace std;

struct R {
    int a, b, c;
};

int r[500001][3], t[500000 * 4 + 1];

bool compare(R a, R b) {
    return a.a < b.a;
}

int update(int n, int i, int v, int f, int l) {
    if (i < f || l < i)
        return t[n];
    
    if (f == l)
        return t[n] = v;
    
    return t[n] = min(
        update(n * 2, i, v, f, (f + l) >> 1),
        update(n * 2 + 1, i, v, ((f + l) >> 1) + 1, l)
    );
}

int get(int n, int f, int l, int le, int ri) {
    if (ri < f || l < le)
        return 1e9;
    
    if (le < f + 1 && l < ri + 1)
        return t[n];
    
    return min(
        get(n * 2, f, (f + l) >> 1, le, ri),
        get(n * 2 + 1, ((f + l) >> 1) + 1, l, le, ri)
    );
}

int main() {
    int n, i, j, s, a = 0;

    cin >> n;

    for (i = 0; i < 3; i++)
        for (j = 1; j < n + 1; j++) {
            cin >> s;
            r[s][i] = j;
        }

    sort((R*)&r[0], (R*)&r[n + 1], compare);

    for (i = 1; i < n + 1; i++)
        update(1, i, 1e9, 1, n);
    
    for (i = 1; i < n + 1; i++) {
        if (r[i][2] < get(1, 1, n, 1, r[i][1]))
            a++;
        update(1, r[i][1], r[i][2], 1, n);
    }

    cout << a;

    return 0;
}
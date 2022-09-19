#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int n, t[1000001 * 4];

void update(int n, int i, int d, int f, int l) {
    if (i < f || l < i)
        return;

    t[n] += d;

    if (f == l)
        return;

    update(n * 2, i, d, f, (f + l) >> 1);
    update(n * 2 + 1, i, d, ((f + l) >> 1) + 1, l);
}

int candy(int n, int i, int f, int l) {
    if (f == l)
        return f;
    
    if (i < t[n * 2] + 1)
        return candy(n * 2, i, f, (f + l) >> 1);
    else
        return candy(n * 2 + 1, i - t[n * 2], ((f + l) >> 1) + 1, l);
}

int main() {
    int a, b, c;

    scanf("%d", &n);

    while (n--) {
        scanf("%d %d", &a, &b);

        if (a == 1) {
            c = candy(1, b, 1, 1000001);
            update(1, c, -1, 1, 1000001);
            printf("%d\n", c);
            continue;
        }

        scanf("%d", &c);
        update(1, b, c, 1, 1000001);
    }

    return 0;
}
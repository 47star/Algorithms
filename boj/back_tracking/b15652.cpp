#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, m, i = 1, j, l[8];

void reset(int o, int d) {
    for (int i = o; i < 8; i++)
        l[i] = d;
}

int main() {
    scanf("%d %d", &n, &m);
    reset(0, 1);

    while (l[0] <= n) {
        for (i = 0; i < m; i++) {
            printf("%d ", l[i]);
        }
        printf("\n");
        i = 0;
        while (++i <= m) {
            if (n < ++l[m - i]) {
                if (m != i) 
                    reset(m - i, l[m - i - 1] + 1);
            } else {
                break;
            }
        }
    }

    return 0;
}
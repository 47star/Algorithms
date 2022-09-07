#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, b, l[500][500], i, j, h, pl, br, tt, th, lt = INT_MAX, mh = 0;
    scanf("%d %d %d", &n, &m, &b);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &l[i][j]);
    
    for (h = 0; h <= 256; h++) {
        pl = 0; br = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
                th = l[i][j] - h;
                if (0 < th)
                    br += th;
                else if (th < 0)
                    pl -= th;
            }
        if (pl <= br + b) {
            tt = pl + br * 2;
            if (tt <= lt) {
                lt = tt;
                mh = h;
            }
        }
    }

    printf("%d %d", lt, mh);

    return 0;
}
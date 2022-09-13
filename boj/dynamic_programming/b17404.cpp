#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, j, o[1000][3], c[1000][3], b = 1000001;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d %d %d", &o[i][0], &o[i][1], &o[i][2]);
    
    for (j = 0; j < 3; j++) {
        c[0][0] = 1000001;
        c[0][1] = c[0][0];
        c[0][2] = c[0][0];
        c[0][j] = o[0][j];

        for (i = 1; i < n; i++) {
            c[i][0] = min(c[i - 1][1], c[i - 1][2]) + o[i][0];
            c[i][1] = min(c[i - 1][0], c[i - 1][2]) + o[i][1];
            c[i][2] = min(c[i - 1][0], c[i - 1][1]) + o[i][2];
        }

        for (i = 0; i < 3; i++)
            if (j != i && c[n - 1][i] < b)
                b = c[n - 1][i];
    }

    printf("%d", b);

    return 0;
}
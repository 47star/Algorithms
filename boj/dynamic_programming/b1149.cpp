#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, c[1000][3];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
    
    for (i = 1; i < n; i++) {
        c[i][0] += min(c[i - 1][1], c[i - 1][2]);
        c[i][1] += min(c[i - 1][0], c[i - 1][2]);
        c[i][2] += min(c[i - 1][0], c[i - 1][1]);
    }

    printf("%d", min(min(c[n - 1][0], c[n - 1][1]), c[n - 1][2]));

    return 0;
}
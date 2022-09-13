#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    char a[1001], b[1001];
    unsigned int lcs[1002][1002];
    unsigned short i, j;
    scanf("%s %s", &a[1], &b[1]);

    for (i = 1; a[i]; i++)
        for (j = 1; b[j]; j++)
            if (a[i] == b[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);

    printf("%u", lcs[i - 1][j - 1]);

    return 0;
}
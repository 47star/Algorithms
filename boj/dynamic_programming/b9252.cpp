#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

char a[1001], b[1001];
unsigned int lcs[1001][1001];

void print(int i, int j) {
    if (lcs[i][j] == 0)
        return;
    if (a[i] == b[j]) {
        print(i - 1, j - 1);
        printf("%c", a[i]);
    } else if (lcs[i][j - 1] < lcs[i - 1][j])
        print(i - 1, j);
    else
        print(i, j - 1);
}

int main() {
    unsigned short i, j, k = 1, l = 1;
    scanf("%s %s", &a[1], &b[1]);

    for (i = 1; a[i]; i++)
        for (j = 1; b[j]; j++)
            if (a[i] == b[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);

    printf("%u\n", lcs[--i][--j]);

    print(i, j);

    return 0;
}
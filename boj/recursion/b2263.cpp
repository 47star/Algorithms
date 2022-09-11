#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, in[100001], post[100001], m[100001];

void p(int ins, int ine, int pos, int poe) {
    if (ine < ins || poe < pos)
        return;

    printf("%d ", post[poe]);

    p(ins, m[post[poe]] - 1, pos, pos + m[post[poe]] - ins - 1);
    p(m[post[poe]] + 1, ine, pos + m[post[poe]] - ins, poe - 1);
}

int main() {
    int i;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        m[in[i]] = i;
    }
    for (i = 1; i <= n; i++)
        scanf("%d", &post[i]);
    
    p(1, n, 1, n);

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, m, p[500001];

int find(int a) {
    if (a == p[a])
        return a;
    return p[a] = find(p[a]);
}

int main() {
    int i, a, b;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
        p[i] = i;
    
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        a = find(a);
        b = find(b);
        if (a == b) {
            printf("%d", i + 1);
            return 0;
        }
        p[b] = a;
    }

    printf("0");

    return 0;
}
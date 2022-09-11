#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, m, num[8], slot[8];
bool u[8];

void fuck(int d) {
    if (d == m) {
        for (int i = 0; i < m; i++)
            printf("%d ", num[slot[i]]);
        printf("\n");
        return;
    }
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (u[i] || p == num[i])
            continue;
        slot[d] = i;
        u[i] = 1;
        p = num[i];
        fuck(d + 1);
        u[i] = 0;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    
    sort(num, num + n);
    
    fuck(0);

    return 0;
}
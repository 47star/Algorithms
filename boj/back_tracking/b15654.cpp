#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, m, num[8];
int u[8];

void fuck(int d) {
    if (d == 0) {
        for (int i = m; 0 < i; i--)
            for (int j = 0; j < n; j++)
                if (u[j] == i)
                    printf("%d ", num[j]);
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (u[i])
            continue;
        u[i] = d;
        fuck(d - 1);
        u[i] = 0;
    }
}

int main() {
    memset(u, 0, 8);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    
    sort(num, num + n);
    
    fuck(m);

    return 0;
}
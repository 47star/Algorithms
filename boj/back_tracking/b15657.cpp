#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, m, num[8], slot[8];

void fuck(int d) {
    if (d == m) {
        for (int i = 0; i < m; i++)
            printf("%d ", num[slot[i]]);
        printf("\n");
        return;
    }
    for (int i = d == 0 ? 0 : slot[d - 1]; i < n; i++) {
        slot[d] = i;
        fuck(d + 1);
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
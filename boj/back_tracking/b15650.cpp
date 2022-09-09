#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v, c;

void cb(int o, int k) {
    if (k == 0) {
        for (int i = 0; i < m; i++)
            printf("%d ", c[i]);
        printf("\n");
        return;
    }

    for (int i = o; i <= n - k; i++) {
        c.push_back(v[i]);
        cb(i + 1, k - 1);
        c.pop_back();
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        v.push_back(i);
    
    cb(0, m);

    return 0;
}
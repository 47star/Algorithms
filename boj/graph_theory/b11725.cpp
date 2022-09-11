#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, a, b, p[100001];
    vector<int> node[100001];
    scanf("%d", &n);

    for (i = 0; i < n - 1; i++) {
        scanf("%d %d", &a, &b);
        node[a].push_back(b);
        node[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        a = q.front();
        q.pop();
        for (i = 0; i < node[a].size(); i++)
            if (p[node[a][i]] == 0 && node[a][i] != 1) {
                p[node[a][i]] = a;
                q.push(node[a][i]);
            }
    }

    for (i = 2; i < n + 1; i++)
        printf("%d\n", p[i]);

    return 0;
}
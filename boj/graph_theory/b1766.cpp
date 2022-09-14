#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, i, a, b, e[32010];
    vector<int> p[32010];
    priority_queue<int> q;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        p[a].push_back(b);
        e[b]++;
    }
    
    for (i = 1; i < n + 1; i++)
        if (e[i] == 0)
            q.push(-i);
    
    while (!q.empty()) {
        a = -q.top();
        q.pop();

        printf("%d ", a);

        for (i = 0; i < p[a].size(); i++) {
            b = p[a][i];
            if (!--e[b])
                q.push(-b);
        }
    }

    return 0;
}
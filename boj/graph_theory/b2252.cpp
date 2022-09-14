#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, i, a, b, e[100010], c, ne;
    vector<int> node[100010];
    queue<int> q;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        e[b]++;
        node[a].push_back(b);
    }

    for (i = 1; i <= n; i++)
        if (e[i] == 0)
            q.push(i);
    
    while (!q.empty()) {
        c = q.front();
        q.pop();

        printf("%d ", c);
        for (i = 0; i < node[c].size(); i++) {
            ne = node[c][i];
            e[ne]--;
            if (e[ne] == 0)
                q.push(ne);
        }
    }

    return 0;
}
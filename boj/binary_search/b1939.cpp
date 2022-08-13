#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define _nm 10000
#define _mm 100000

struct Edge {
    unsigned int dst;
    unsigned int capa;
};

unsigned int n, m, i, a, b, c, src, dst, low = 0, mid, high = 0, cur, len;
Edge cur_edge;

bool visited[_nm];
vector<Edge> graph[_mm];

bool bfs(unsigned int capa) {
    queue<unsigned int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur == dst)
            return true;
        
        len = graph[cur].size();

        for (i = 0; i < len; i++) {
            cur_edge = graph[cur].at(i);
            if (!visited[cur_edge.dst] && capa <= cur_edge.capa) {
                visited[cur_edge.dst] = true;
                q.push(cur_edge.dst);
            }
        }
    }

    return false;
}

int main() {
    scanf("%u %u", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%u %u %u", &a, &b, &c);
        a--; b--;
        graph[a].push_back(Edge { b, c });
        graph[b].push_back(Edge { a, c });
        if (high < c)
            high = c;
    }

    scanf("%u %u", &src, &dst);
    src--; dst--;

    while (low <= high) {
        memset(visited, false, sizeof(visited));

        mid = (low + high) >> 1;

        if (bfs(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("%u", high);

    return 0;
}
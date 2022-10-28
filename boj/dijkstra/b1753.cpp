#include <bits/stdc++.h>

using namespace std;

#define ii pair<uint32_t, uint32_t>
#define p(a, b) make_pair(a, b)

vector<ii> A[20001];
priority_queue<ii, vector<ii>, greater<ii>> Q;
uint32_t t[20001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    uint32_t V, E, S, u, v, w, i, l;
    ii c;

    scanf("%u %u %u", &V, &E, &S);

    for (i = 0; i < V + 1; i++) 
        t[i] = 1e9;

    for (i = 0; i < E; i++) {
        scanf("%u %u %u", &u, &v, &w);
        A[u].push_back(p(v, w));
    }

    Q.push(p(0, S));
    t[S] = 0;

    while (!Q.empty()) {
        c = Q.top();
        Q.pop();

        l = A[c.second].size();
        for (i = 0; i < l; i++) {
            v = A[c.second][i].first;
            w = t[c.second] + A[c.second][i].second;
            
            if (w < t[v]) {
                Q.push(p(w, v));
                t[v] = w;
            }
        }
    }

    for (i = 1; i < V + 1; i++)
        if (t[i] == 1e9)
            printf("INF\n");
        else
            printf("%u\n", t[i]);

    return 0;
}
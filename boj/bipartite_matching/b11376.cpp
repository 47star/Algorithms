#include <bits/stdc++.h>

using namespace std;

vector<int> vtx[1001];
int slot[1001];
bool done[1001];

bool dfs(int x) {
    done[x] = true;
    int s = vtx[x].size();
    for (int i = 0; i < s; i++) {
        int p = vtx[x][i];

        if (slot[p] == 0 || !done[slot[p]] && dfs(slot[p])) {
            slot[p] = x;
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int n, m;

    scanf("%d %d", &n, &m);
    n++;

    int i, j, c, w, r = 0;

    for (i = 1; i < n; i++) {
        scanf("%d", &c);
        for (j = 0; j < c; j++) {
            scanf("%d", &w);
            vtx[i].push_back(w);
        }
    }

    for (i = 1; i < n; i++) {
        memset(done, false, sizeof(done));
        if (dfs(i))
            r++;
        memset(done, false, sizeof(done));
        if (dfs(i))
            r++;
    }

    printf("%d", r);

    return 0;
}
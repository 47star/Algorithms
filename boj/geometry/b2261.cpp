#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

inline int dist(pair<int, int> a, pair<int, int> b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main() {
    int n, x, y, z, i;
    set<pair<int, int>> s;
    vector<pair<int, int>> v;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());

    s.insert(make_pair(v[0].second, v[0].first));
    s.insert(make_pair(v[1].second, v[1].first));

    x = dist(v[0], v[1]);
    y = 0;

    for (i = 2; i < n; i++) {
        while (y < i && x < pow(v[i].first - v[y].first, 2)) {
            s.erase(make_pair(v[y].second, v[y].first));
            y++;
        }
        
        auto f = s.lower_bound(make_pair(v[i].second - sqrt(x), -(1 << 30)));
        auto l = s.upper_bound(make_pair(v[i].second + sqrt(x), 1 << 30));

        for (auto j = f; j != l; j++)
            x = min(x, dist(make_pair(j->second, j->first), v[i]));
        
        s.insert(make_pair(v[i].second, v[i].first));
    }

    printf("%d", x);

    return 0;
}
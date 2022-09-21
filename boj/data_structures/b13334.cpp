#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main() {
    int n, d, i, a, b, m = 0, t;
    vector<pair<int, int>> q;
    priority_queue<int, vector<int>, greater<int>> pq;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        q.push_back(b < a ? make_pair(b, a) : make_pair(a, b));
    }

    scanf("%d", &d);

    sort(q.begin(), q.end(), comp);

    for (i = 0; i < q.size(); i++) {
        a = q[i].second;
        b = q[i].first;

        if (d < a - b)
            continue;
        
        pq.push(b);

        while (!pq.empty()) {
            t = pq.top();

            if (a - t < d + 1)
                break;

            pq.pop();
        }

        if (m < pq.size())
            m = pq.size();
    }

    printf("%d", m);

    return 0;
}
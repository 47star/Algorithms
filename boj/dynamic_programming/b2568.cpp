#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, c;
    scanf("%d", &n);
    vector<int> s, a;
    vector<pair<long long, long long>> v(n), t;

    for (i = 0; i < n; i++)
        scanf("%lld %lld", &v[i].first, &v[i].second);
    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (s.empty() || s.back() < v[i].second) {
            t.push_back(make_pair(s.size(), v[i].first));
            s.push_back(v[i].second);
        } else {
            auto it = lower_bound(s.begin(), s.end(), v[i].second);
            *it = v[i].second;
            t.push_back(make_pair(it - s.begin(), v[i].first));
        }
    }

    c = s.size() - 1;
    for (i = t.size() - 1; 0 <= i; i--) {
        if (t[i].first == c)
            c--;
        else
            a.push_back(t[i].second);
    }
    sort(a.begin(), a.end());

    printf("%lu", a.size());
    for (i = 0; i < a.size(); i++)
        printf("\n%d", a[i]);

    return 0;
}
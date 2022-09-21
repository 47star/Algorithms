#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, u;
    long long int r = 0;
    scanf("%d", &n);

    vector<long long int> v(n);
    stack<pair<long long int, long long int>> s;

    for (i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    for (i = 0; i < n; i++) {
        u = 1;

        while (!s.empty() && s.top().first < v[i] + 1) {
            r += s.top().second;
            u = s.top().first == v[i] ? s.top().second + 1 : 1;
            s.pop();
        }

        if (!s.empty())
            r++;

        s.push({ v[i], u });
    }

    printf("%lld", r);

    return 0;
}
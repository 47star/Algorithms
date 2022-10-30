#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, c[1000001];
vector<int> prime;

inline bool v(ll m) {
    for (auto p : prime) {
        if (m % p == 0)
            return false;
    }
    return true;
}

int main() {
    ll s, i, j;

    scanf("%d", &n);

    for (i = 2; i < 1000001; i++) {
        if (c[i])
            continue;
        
        for (j = i + i; j < i + 1; j += i) {
            c[j] = 1;
        }
    }

    for (i = 2; i <= 1000000; i++) {
        if (!c[i])
            prime.push_back(i);
    }

    for (i = 0, s; i < n; i++) {
        scanf("%lld", &s);
        printf(v(s) ? "YES\n" : "NO\n");
    }

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define lld long long int
#define MOD (int)(1e9 + 7)

using namespace std;

lld pow(lld n, int m) {
    return m == 1 ? n : n * pow(n, m - 1);
}

lld pp(lld n, lld k) {
    if (k == 0)
        return 1;
        
    if (k == 1)
        return n;

    lld r = pow(pp(n, k / 2), 2) % MOD;

    if (k % 2)
        r *= n;
    
    return r % MOD;
}

int main() {
    int n, i;
    lld a = 0;

    cin >> n;

    vector<int> v(n);

    for (i = 0; i < n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    for (i = 0; i < n; i++)
        a = (a + (v[i] * (pp(2, i) + MOD - pp(2, n - i - 1)))) % MOD;
    
    cout << a;

    return 0;
}
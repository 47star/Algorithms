#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int n, k, ar[30], le[30], pw[70];
lld dp[1 << 15][120];
string s[30];

lld fuck(int a, int b) {
    lld &r = dp[a][b];

    if (r != -1)
        return r;
    
    if (a == (1 << n) - 1)
        return r = b ? 0 : 1;
    
    r = 0;

    for (int i = 0; i < n; i++)
        if (!(a & (1 << i)))
            r += fuck(a | (1 << i), (b * pw[le[i]] + ar[i]) % k);
    
    return r;
}

int main() {
    memset(dp, -1, sizeof dp);

    int i;
    lld p, q = 1;

    cin >> n;

    for (i = 0; i < n; i++)
        cin >> s[i];
    
    cin >> k;

    pw[0] = 1 % k;
    for (i = 1; i < 70; i++)
        pw[i] = pw[i - 1] * 10 % k;

    for (i = 0; i < n; i++) {
        le[i] = s[i].size();

        for (auto c : s[i])
            ar[i] = (ar[i] * 10 + c - '0') % k;
    }

    p = fuck(0, 0);

    if (p == 0) {
        cout << "0/1";
        return 0;
    }

    for (i = 1; i < n + 1; i++)
        q *= i;
    
    lld g = __algo_gcd(p, q);
    cout << p / g << "/" << q / g;

    return 0;
}
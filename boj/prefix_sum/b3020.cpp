#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h, t[500003], b[500003], i, im, tc, bc;
    memset(t, 0, sizeof(t));
    memset(b, 0, sizeof(b));

    cin >> n >> h;

    im = (n >> 1) + 1;
    for (i = 1; i < im; i++) {
        cin >> bc >> tc;
        b[bc]++;
        t[h - tc + 1]++;
    }
    
    im = h + 1;
    for (i = 1; i < im; i++)
        b[i] += b[i - 1];

    for (i = h; 0 < i; i--)
        t[i] += t[i + 1];
    
    int m = n, c = 0, d;
    for (i = 1; i < im; i++) {
        d = b[h] - b[i - 1] + t[1] - t[i + 1];

        if (d < m) {
            m = d;
            c = 1;
        } else if (d == m)
            c++;
    }

    cout << m << " " << c;

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, j, mi = INT32_MAX, mii, ma, c[1000][2];
    
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> c[i][0] >> c[i][1];
    
    for (i = 0; i < n; i++) {
        ma = 0;
        
        for (j = 0; j < n; j++)
            if (i != j)
                ma = max(ma, (int)sqrt((c[i][0] - c[j][0]) * (c[i][0] - c[j][0]) + (c[i][1] - c[j][1]) * (c[i][1] - c[j][1])));

        if (ma < mi) {
            mi = ma;
            mii = i;
        }
    }

    cout << c[mii][0] << " " << c[mii][1];

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

string p[101][101];

string c(int n, int m) {
    if (n == m || m == 0)
        return "1";

    if (p[n][m] != "")
        return p[n][m];
    
    p[n][m] = "";
    string a = c(n - 1, m - 1), b = c(n - 1, m);

    int sum = 0, size = max(a.size(), b.size());

    for (int i = 0; i < size || sum; i++) {
        if (i < a.size())
            sum += a[i] - '0';
        if (i < b.size())
            sum += b[i] - '0';
        p[n][m] += sum % 10 + '0';
        sum /= 10;
    }

    return p[n][m];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    c(n, m);

    for (int i = p[n][m].size() - 1; 0 <= i; i--)
        printf("%c", p[n][m][i]);

    return 0;
}
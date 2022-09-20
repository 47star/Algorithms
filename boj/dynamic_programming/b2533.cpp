#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int dp[1000001][2], v[1000001];
vector<int> e[1000001];

void f(int a) {
    v[a] = 1;
    dp[a][0] = 1;

    for (int i = 0; i < e[a].size(); i++) {
        if (v[e[a][i]])
            continue;

        f(e[a][i]);

        dp[a][0] += min(dp[e[a][i]][0], dp[e[a][i]][1]);
        dp[a][1] += dp[e[a][i]][0];
    }
}

int main() {
    int n, a, b;

    scanf("%d", &n);
    n--;

    while (n--) {
        scanf("%d %d", &a, &b);

        e[a].push_back(b);
        e[b].push_back(a);
    }

    f(1);   

    printf("%d", min(dp[1][0], dp[1][1]));

    return 0;
}
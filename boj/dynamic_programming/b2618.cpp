#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int n, w, e[1001][2], dp[1001][1001];

inline int part(int t, int p, int next) {
    if (t == 0)
        return abs(e[next][0] - p) + abs(e[next][1] - p);
    return abs(e[next][0] - e[t][0]) + abs(e[next][1] - e[t][1]);
}

int dist(int a, int b) {
    if (a == w || b == w)
        return 0;
    
    if (dp[a][b] != -1)
        return dp[a][b];
    
    int next = max(a, b) + 1;

    return dp[a][b] = min(
        part(a, 1, next) + dist(next, b),
        part(b, n, next) + dist(a, next)
    );
}

void print(int a, int b) {
    if (a == w || b == w)
        return;
    
    int next = max(a, b) + 1;

    if (dp[next][b] + part(a, 1, next) < dp[a][next] + part(b, n, next)) {
        printf("1\n");
        print(next, b);
    } else {
        printf("2\n");
        print(a, next);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));

    scanf("%d\n%d", &n, &w);

    for (int i = 1; i < w + 1; i++)
        scanf("%d %d", &e[i][0], &e[i][1]);

    printf("%d\n", dist(0, 0));
    print(0, 0);

    return 0;
}
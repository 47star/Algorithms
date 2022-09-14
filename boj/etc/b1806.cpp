#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s, i, a[100000];
    
    scanf("%d %d", &n, &s);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int l = 0, h = 0, sum = a[0], len = n + 1;

    while (l < h + 1 && h < n) {
        if (sum < s)
            sum += a[++h];
        else {
            len = min(len, h - l + 1);
            sum -= a[l++];
        }
    }

    printf("%d", len == n + 1 ? 0 : len);

    return 0;
}
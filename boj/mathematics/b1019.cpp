#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int i = 1, j, n, c[10] = { 0, }, a = 0, cur;
    
    scanf("%d", &n);

    while (n != 0) {
        cur = n % 10;
        n /= 10;

        c[0] -= i;

        for (j = 0; j < cur; j++)
            c[j] += (n + 1) * i;

        c[cur] += n * i + 1 + a;

        for (j = cur + 1; j < 10; j++)
            c[j] += n * i;

        a += cur * i;
        i *= 10;
    }

    for (i = 0; i < 10; i++)
        printf("%d ", c[i]);

    return 0;
}
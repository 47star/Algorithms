#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool star(unsigned short x, unsigned short y, unsigned short n) {
    if ((x / n) % 3 == 1 && (y / n) % 3 == 1)
        return false;
    else if (n / 3 == 0)
        return true;
    else
        return star(x, y, n / 3);
}

int main() {
    unsigned short n, x, y;
    scanf("%hu", &n);

    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++)
            if (star(x, y, n))
                printf("*");
            else
                printf(" ");
        printf("\n");
    }

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned short e, s, m, y = 1;
    scanf("%hu %hu %hu", &e, &s, &m);

    while (true) {
        if ((y - e) % 15 == 0 && (y - s) % 28 == 0 && (y - m) % 19 == 0)
            break;
        y++;
    }

    printf("%hu", y);

    return 0;
}
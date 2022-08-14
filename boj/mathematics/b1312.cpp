#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int a, b, n, i, r = 0;
    scanf("%u %u %u", &a, &b, &n);

    if (a % b == 0) {
        printf("0");
        return 0;
    }

    if (b < a)
        a %= b;
    
    for (i = 0; i < n; i++) {
        a *= 10;
        r = a / b;
        a %= b;
    }

    printf("%u", r);

    return 0;
}
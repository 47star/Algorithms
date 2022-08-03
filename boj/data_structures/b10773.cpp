#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int t = 0, k, i, a;
    
    scanf("%u", &k);

    unsigned int* h = (unsigned int*)malloc(k * sizeof(unsigned int));

    for (i = 0; i < k; i++) {
        scanf("%u", &a);
        if (a == 0) {
            t--;
            continue;
        }
        h[t++] = a;
    }

    a = 0;

    for (i = 0; i < t; i++) {
        a += h[i];
    }

    printf("%u", a);

    return 0;
}
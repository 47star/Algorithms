#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n, i;
    unsigned long result = 0, sum;
    unsigned short ropes[100000];
    scanf("%u", &n);

    for (i = 0; i < n; i++)
        scanf("%hu", &ropes[i]);
    
    sort(ropes, ropes + n, greater<unsigned short>());

    for (i = 0; i < n; i++) {
        sum = ropes[i] * (i + 1);
        if (result < sum)
            result = sum;
    }

    printf("%lu", result);

    return 0;
}
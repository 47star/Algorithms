#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

unsigned short n, i;
unsigned int r;
unsigned short a[50], b[50];

int main() {
    scanf("%hu", &n);

    for (i = 0; i < n; i++)
        scanf("%hu", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%hu", &b[i]);
    
    sort(a, a + n);
    sort(b, b + n, greater<unsigned short>());

    r = 0;
    for (i = 0; i < n; i++)
        r += a[i] * b[i];

    printf("%u", r);

    return 0;
}
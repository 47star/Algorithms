#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned short n;
    scanf("%hu", &n);

    if (n == 4 || n == 7)
        printf("-1");
    else if (n % 5 == 0)
        printf("%hu", n / 5);
    else
        printf("%hu", n / 5 + 1 + ((n % 5) % 2 == 0));
    
    return 0;
}
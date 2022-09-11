#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

long a, b, c, d;

long p(long a, long e) {
    if (e == 1)
        return a % c;
    
    d = p(a, e / 2);

    return e % 2 == 0 ? d * d % c : (d * d % c) * a % c;
}

int main() {
    scanf("%ld %ld %ld", &a, &b, &c);

    printf("%ld", p(a, b));

    return 0;
}
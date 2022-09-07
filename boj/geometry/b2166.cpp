#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    short n;
    long double r = 0;
    double p[3][2];

    scanf("%hd %lf %lf %lf %lf", &n, &p[0][0], &p[0][1], &p[1][0], &p[1][1]);
    n -= 2;

    while (n--) {
        scanf("%lf %lf", &p[2][0], &p[2][1]);
        r += (p[0][0] * p[1][1] + p[1][0] * p[2][1] + p[2][0] * p[0][1] - p[1][0] * p[0][1] - p[2][0] * p[1][1] - p[0][0] * p[2][1]) / 2;
        p[1][0] = p[2][0];
        p[1][1] = p[2][1];
    }

    printf("%.1Lf", abs(r));

    return 0;
}
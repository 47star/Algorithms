#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    short p[3][2], v[2][2];
    int s;

    scanf("%hd %hd\n%hd %hd\n%hd %hd", &p[0][0], &p[0][1], &p[1][0], &p[1][1], &p[2][0], &p[2][1]);

    v[0][0] = p[1][0] - p[0][0];
    v[0][1] = p[1][1] - p[0][1];
    v[1][0] = p[2][0] - p[1][0];
    v[1][1] = p[2][1] - p[1][1];

    s = v[0][0] * v[1][1] - v[0][1] * v[1][0];

    printf("%d", 0 < s ? 1 : (s < 0 ? -1 : 0));

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);

    printf("%d", (v - b - 1) / (a - b) + 1);

    return 0;
}
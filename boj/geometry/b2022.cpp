#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long double x, y, c;
    scanf("%Lf %Lf %Lf", &x, &y, &c);

    long double low = 1, high = min(x, y), mid, h1, h2, ans;

    while (low + 0.001 <= high) {
        mid = (low + high) / 2;

        h1 = pow(pow(x, 2) - pow(mid, 2), 0.5);
        h2 = pow(pow(y, 2) - pow(mid, 2), 0.5);
        h1 = (h1 * h2) / (h1 + h2);

        if (c <= h1) {
            ans = mid;
            low = mid;
        } else
            high = mid;
    }

    printf("%.3Lf", ans);

    return 0;
}
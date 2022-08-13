#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool compare(unsigned int a, unsigned int b) {
    return a < b;
}

int main() {
    unsigned int n, c, i, quantity, a, mid, min = 1, max;

    scanf("%u %u", &n, &c);

    unsigned int *house = (unsigned int*)malloc(n * sizeof(unsigned int));

    for (i = 0; i < n; i++)
        scanf("%u", &house[i]);
    
    sort(house, house + n, compare);

    max = house[n - 1] - house[0] + 1;

    while (min < max) {
        mid = (min + max) >> 1;

        quantity = 1;
        a = house[0];

        for (i = 1; i < n && quantity <= c; i++) {
            if (mid <= house[i] - a) {
                quantity++;
                a = house[i];
            }
        }

        if (quantity < c)
            max = mid;
        else
            min = mid + 1;
    }

    printf("%u", min - 1);

    return 0;
}
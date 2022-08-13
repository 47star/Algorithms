#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    unsigned int n, m, i, min, max, mid;
    int a;

    scanf("%u", &n);

    int *cards = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &cards[i]);

    sort(cards, cards + n, compare);

    scanf("%u", &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &a);

        min = 0;
        max = n;

        while (min < max) {
            mid = (min + max) >> 1;

            if (a < cards[mid])
                max = mid;
            else if (cards[mid] < a)
                min = mid + 1;
            else
                break;
        }

        printf("%d ", cards[mid] == a);
    }

    return 0;
}
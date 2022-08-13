#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int n, m, i, a, min, max, mid, lb;
    
    scanf("%d", &n);

    int *cards = (int*)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &cards[i]);
    
    sort(cards, cards + n, compare);
    
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &a);
        
        min = 0;
        max = n;
        
        while (min < max) {
            mid = (min + max) >> 1;

            if (a <= cards[mid])
                max = mid;
            else
                min = mid + 1;
        }

        lb = min;
        
        min = 0;
        max = n;

        while (min < max) {
            mid = (min + max) >> 1;

            if (a < cards[mid])
                max = mid;
            else
                min = mid + 1;
        }

        printf("%d ", min - lb);
    }


    return 0;
}
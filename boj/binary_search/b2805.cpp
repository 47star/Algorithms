#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n, m, i, mid, min = 0, max = 0;
    unsigned long sum;
    scanf("%u %u", &n, &m);

    unsigned int *tree = (unsigned int*)malloc(n * sizeof(unsigned int));

    for (i = 0; i < n; i++) {
        scanf("%u", &tree[i]);

        if (max < tree[i])
            max = tree[i];
    }

    while (min < max) {
        mid = (min + max) >> 1;

        sum = 0;
        
        for (i = 0; i < n; i++)
            if (mid < tree[i])
                sum += tree[i] - mid;

        if (sum < m)
            max = mid;
        else
            min = mid + 1;
    }

    printf("%u", min - 1);

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n, i, len = 1, min, max, mid;

    scanf("%u", &n);

    unsigned int *seq = (unsigned int*)malloc(n * sizeof(unsigned int));
    unsigned int *lis = (unsigned int*)malloc(n * sizeof(unsigned int));

    for (i = 0; i < n; i++)
        scanf("%u", &seq[i]);

    lis[0] = seq[0];

    for (i = 0; i < n; i++) {
        if (lis[len - 1] < seq[i])
            lis[len++] = seq[i];
        else {
            min = 0;
            max = len;

            while (min < max) {
                mid = (min + max) >> 1;

                if (seq[i] <= lis[mid])
                    max = mid;
                else
                    min = mid + 1;
            }

            lis[min] = seq[i];
        }
    }

    printf("%u", len);

    return 0;
}
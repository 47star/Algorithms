#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, len = 1, a = 0, min, max, mid;

    scanf("%d", &n);

    int *seq = (int*)malloc(n * sizeof(int));
    int *lis = (int*)malloc(n * sizeof(int));
    int *ptr = (int*)malloc(n * sizeof(int));
    int *arr = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &seq[i]);

    lis[0] = seq[0];
    ptr[0] = 0;

    for (i = 1; i < n; i++) {
        if (lis[len - 1] < seq[i]) {
            ptr[i] = len;
            lis[len++] = seq[i];
        } else {
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
            ptr[i] = min;
        }
    }

    for (i = n; 0 < i--;) {
        if (ptr[i] == len - 1) {
            arr[a++] = seq[i];
            len--;
        }
    }

    printf("%d\n", a);
    for (i = a; 0 < i--;)
        printf("%d ", arr[i]);

    return 0;
}
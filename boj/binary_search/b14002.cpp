#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned short n, i, len = 1, a = 0, min, max, mid;

    scanf("%hu", &n);

    unsigned short *seq = (unsigned short*)malloc(n * sizeof(unsigned short));
    unsigned short *lis = (unsigned short*)malloc(n * sizeof(unsigned short));
    unsigned short *ptr = (unsigned short*)malloc(n * sizeof(unsigned short));
    unsigned short *arr = (unsigned short*)malloc(n * sizeof(unsigned short));

    for (i = 0; i < n; i++)
        scanf("%hu", &seq[i]);

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

    printf("%hu\n", a);
    for (i = a; 0 < i--;)
        printf("%hu ", arr[i]);

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, i, a, first, last, mid;

    scanf("%d", &n);

    int* l = (int*)calloc(n, sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        l[i] = a;
    }

    sort(l, l + n);

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &a);

        first = 0;
        last = n - 1;

        while (true) {
            if (last - first < 0) {
                printf("0\n");
                break;
            }
            
            mid = (first + last) / 2;

            if (l[mid] == a) {
                printf("1\n");
                break;
            }
            
            if (a < l[mid]) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
    }
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, min, start, end, sum, ans1, ans2;
    
    scanf("%d", &n);

    min = 2000000000;
    start = 0;
    end = n - 1;

    int *solus = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &solus[i]);

    while (start < end) {
        printf("\n%d %d", start, end);
        sum = solus[start] + solus[end];

        if (abs(sum) < min) {
            printf("!!!");
            min = abs(sum);
            ans1 = solus[start];
            ans2 = solus[end];

            if (sum == 0)
                break;
        }

        if (sum < 0)
            start++;
        else
            end--;
    }

    printf("\n%d %d", ans1, ans2);

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int n, i, j;
    long sum, lb, low, high, mid, result = 0;

    scanf("%d", &n);

    int abcd[4][4000];

    for (i = 0; i < n; i++)
        for (j = 0; j < 4; j++)
            scanf("%d", &abcd[j][i]);
    
    vector<long> v;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            v.push_back(abcd[2][i] + abcd[3][j]);
    
    sort(v.begin(), v.end());

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            sum = (abcd[0][i] + abcd[1][j]) * -1;

            low = 0;
            high = v.size();

            while (low < high) {
                mid = (low + high) >> 1;

                if (sum <= v[mid])
                    high = mid;
                else
                    low = mid + 1;
            }

            lb = low;

            low = 0;
            high = v.size();

            while (low < high) {
                mid = (low + high) >> 1;

                if (sum < v[mid])
                    high = mid;
                else
                    low = mid + 1;
            }

            if (sum == v[lb])
                result += (low - lb);
        }
    
    printf("%ld", result);

    return 0;
}
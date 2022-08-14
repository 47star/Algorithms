#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int n, i, j;
    long low, high, sum, result = 0;

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
            sum = abcd[0][i] + abcd[1][j];

            low = lower_bound(v.begin(), v.end(), -sum) - v.begin();
            high = upper_bound(v.begin(), v.end(), -sum) - v.begin();

            if (-sum == v[low])
                result += high - low;
        }
    
    printf("%ld", result);

    return 0;
}
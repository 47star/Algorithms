#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned short k, i;
    unsigned int n, quantity, mid, min = 0, max = 0;
    
    scanf("%hu %u", &k, &n);

    unsigned int *cables = (unsigned int*)malloc(k * sizeof(unsigned int));

    for (i = 0; i < k; i++) {
        scanf("%u", &cables[i]);
        if (max < cables[i])
            max = cables[i];
    }

    max++;
    
    while (min < max) {
        mid = (min + max) >> 1;
        
        quantity = 0;

        for (i = 0; i < k && quantity <= n; i++)
            quantity += cables[i] / mid;

        if (quantity < n)
            max = mid;
        else
            min = mid + 1;
    }

    printf("%u", min - 1);

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c = 1;
    scanf("%d %d", &a, &b);
    
    while (a < b) {
        c++;
        
        if (b % 10 == 1)
            b /= 10;
        else if (b % 2 == 0)
            b /= 2;
        else
            break;
    }

    printf("%d", a == b ? c : -1);

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool compare(char a, char b) {
    return b < a;
}

int main() {
    char *n = (char*)calloc(100000, sizeof(char));
    scanf("%s", n);
    
    bool zero = false;
    int i;
    unsigned int sum = 0;
    for (i = 0; i < 100000 && n[i]; i++) {
        if (n[i] - 48 == 0)
            zero = true;
        sum += n[i] - 48;
    }

    if (zero && sum % 3 == 0) {
        sort(n, n + i, compare);
        printf("%s", n);
    } else {
        printf("-1");
    }

    return 0;
}
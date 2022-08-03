#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

int main() {
    int c = 0, n, a, i = 0, head = -1, hi = 0;
    
    scanf("%d", &n);
    
    int* stack = (int*)malloc(n * sizeof(int));
    bool* hist = (bool*)malloc(n * 2 * sizeof(bool));
    
    while (-1 < c && c++ < n) {
        scanf("%d", &a);
        a--;
        
        while (head == -1 || stack[head] < a) {
            if (a < i) {
                c = -1;
                break;
            }
            stack[++head] = i++;
            hist[hi++] = true;
        }
        while (head != -1 && a <= stack[head]) {
            head--;
            hist[hi++] = false;
        }
    }
    
    if (c == -1) {
        printf("NO");
    } else {
        for (i = 0; i < hi; i++) {
            if (hist[i])
                printf("+\n");
            else
                printf("-\n");
        }
    }
    
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    bool sw = false;
    scanf("%d", &n);

    queue<int> q;
    for (i = 1; i <= n; i++)
        q.push(i);
    
    while (q.size() != 1) {
        q.pop();
        if(sw = !sw)
            q.push(q.front());
    }

    printf("%d", q.front());

    return 0;
}
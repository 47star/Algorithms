#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, j, a = 0, s = 0, l = 0, h = 0;
    vector<int> p;
    vector<bool> c;

    scanf("%d", &n);
    c.resize(n + 1, true);
    for (i = 2; i * i <= n; i++) 
        if (c[i])
            for (j = i * 2; j <= n; j += i)
                c[j] = false;
    
    for (i = 2; i <= n; i++)
        if (c[i])
            p.push_back(i);
    
    while (true) {
        if (n <= s)
            s -= p[l++];
        else if (h == p.size())
            break;
        else
            s += p[h++];

        if (s == n)
            a++;
    }

    printf("%d", a);

    return 0;
}
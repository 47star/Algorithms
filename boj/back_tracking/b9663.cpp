#include <bits/stdc++.h>

using namespace std;

char n, b[14];
int c = 0;

void a(char m) {
    if (n == m) {
        c++;
        return;
    }

    char nm = m + 1;

    for (char i = 0; i < n; i++) {
        b[m] = i;

        bool p = true;
        
        for (char j = 0; j < m; j++) {
            if (i == b[j] || m - j == abs(b[m] - b[j])) {
                p = false;
                break;
            }
        }

        if (p)
            a(nm);
    }
}

int main() {
    scanf("%hhd", &n);
    a(0);
    printf("%d", c);

    return 0;
}
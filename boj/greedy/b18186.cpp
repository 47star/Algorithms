#include <stdio.h>
#include <algorithm>

using namespace std;

long long n, b, c, v[1000002], r = 0, i, m;

int main() {
    scanf("%lld %lld %lld", &n, &b, &c);
    
    for (i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    if (b < c) {
        for (i = 0; i < n; i++)
            r += v[i];
        printf("%lld", r * b);
        return 0;
    }

    for (i = 0; i < n; i++) {
        if (v[i + 2] < v[i + 1]) {
            m = min(v[i], v[i + 1] - v[i + 2]);
            r += m * (b + c);
            v[i] -= m;
            v[i + 1] -= m;

            m = min(v[i], min(v[i + 1], v[i + 2]));
            r += m * (b + c * 2);

            v[i] -= m;
            v[i + 1] -= m;
            v[i + 2] -= m;
        } else {
            m = min(v[i], min(v[i + 1], v[i + 2]));
            r += m * (b + c * 2);
            v[i] -= m;
            v[i + 1] -= m;
            v[i + 2] -= m;

            m = min(v[i], v[i + 1]);
            r += m * (b + c);
            v[i] -= m;
            v[i + 1] -= m;
        }
        r += b * v[i];
        v[i] = 0;
    }

    printf("%lld", r);
    
    return 0;
}
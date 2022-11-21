#include <bits/stdc++.h>

using namespace std;

int n, a[500001], t[500001];
long long r = 0;

void ms(int s, int e) {
    if (s < e) {
        int m = (s + e) >> 1;

        ms(s, m);
        ms(m + 1, e);
        
        int i = s, j = m + 1, k = s;
        long long c = 0;

        while (i < m + 1 && j < e + 1) {
            if (a[i] < a[j] + 1) {
                t[k++] = a[i++];
                r += c;
            } else {
                t[k++] = a[j++];
                c++;
            }
        }

        if (m < i) {
            int p = j;
            while (p < e + 1) {
                t[k++] = a[p++];
                c++;
            }
        } else {
            int p = i;
            while (p < m + 1) {
                t[k++] = a[p++];
                r += c;
            }
        }

        for (i = s; i < e + 1; i++)
            a[i] = t[i];
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    ms(0, n - 1);
    printf("%lld", r);

    return 0;
}
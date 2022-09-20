#include <bits/stdc++.h>

using namespace std;

int a[100001], t[400001];

int init(int n, int f, int l) {
	if (f == l)
        return t[n] = f;

	int x = init(n * 2, f, (f + l) >> 1), y = init(n * 2 + 1, ((f + l) >> 1) + 1, l);

	if (a[x] == a[y])
        return t[n] = min(x, y);

	if (a[y] < a[x])
        swap(x, y);
    
	return t[n] = x;
}

int query(int n, int f, int l, int le, int ri) {
	if (le < f + 1 && l < ri + 1)
        return t[n];

	if (l < le || ri < f)
        return 0;

	int x = query(n * 2, f, (f + l) >> 1, le, ri), y = query(n * 2 + 1, ((f + l) >> 1) + 1, l, le, ri);
	if (a[x] == a[y]) return min(x, y);
	if (a[x] > a[y]) return y;
	else return x;
}

int update(int n, int i, int f, int l) {
	if (i < f || l < i)
        return t[n];

	if (f == l)
        return i;
    
	int x = update(n * 2, i, f, (f + l) >> 1), y = update(n * 2 + 1, i, ((f + l) >> 1) + 1, l);

	if (a[x] == a[y])
        return t[n] = min(x, y);

	if (a[y] < a[x])
        swap(x, y);
    
	return t[n] = x;
}

int main() {
	int n, m, i, j, k;

	a[0] = 1e9 + 1;

	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++)
        scanf("%d", &a[i]);

	init(1, 1, n);

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d %d", &i, &j, &k);
		if (i == 1) {
			a[j] = k;
			update(1, j, 1, n);
            continue;
		}

        printf("%d\n", query(1, 1, n, j, k));
	}
}
#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

unsigned int n, m, r;
unsigned int* p;

unsigned int find(unsigned int a) {
	if (p[a] == a)
		return a;
	r = find(p[a]);
	p[a] = r;
	return r;
}

void uni(unsigned int a, unsigned int b) {
	unsigned int ap = find(a);
	unsigned int bp = find(b);
	if (ap < bp)
		p[bp] = ap;
	else
		p[ap] = bp;
}

int main() {
	unsigned int i, a, b;
	char ins;

	scanf("%u %u", &n, &m);

	p = (unsigned int*)malloc((n + 1) * sizeof(unsigned int));

	for (i = 0; i <= n; i++)
		p[i] = i;

	for (i = 0; i < m; i++) {
		scanf("%hhd %u %u", &ins, &a, &b);
		if (ins == 0)
			uni(a, b);
		else {
			if (a == b || find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	
	return 0;
}
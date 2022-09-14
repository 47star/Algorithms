#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int p[100001];

int find(int i) {
	return p[i] == i ? i : p[i] = find(p[i]);
}

int main() {
	int i, n, m, r = 0, a, b, c;

	scanf("%d %d", &n, &m);

	vector<pair<int, pair<int, int>>> node(m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		node[i] = make_pair(c, make_pair(a, b));
	}

	for (int i = 1; i < n + 1; i++)
		p[i] = i;

	sort(node.begin(), node.end());

    c = 0;

	for (i = 0; i < m; i++) {
		a = find(node[i].second.first);
		b = find(node[i].second.second);
		if (a != b) {
			c = max(c, node[i].first);
			r += node[i].first;
			p[a] = b;
		}
	}
	cout << r - c;

	return 0;
}
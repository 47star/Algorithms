#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, t, i, j;
    string tt, s;
    set<string> set;

	cin >> n;

	for (i = 0; i < n; i++){
		cin >> k;

		s = "";

		for (j = 0; j < k; j++) {
			cin >> tt;
			set.insert(s += "/" + tt);
		}
	}
	
	for (auto v : set) {
		j = count(v.begin(), v.end(), '/') - 1;

		for (i = 0; i < j; i++)
            cout << "--";

		cout << v.substr(v.find_last_of("/") + 1) << '\n';
	}
}
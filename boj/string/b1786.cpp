#include <bits/stdc++.h>

using namespace std;

string t, p;
vector<int> table;
vector<int> idx;
int answer = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    getline(cin, t);
    getline(cin, p);

    table.resize(p.size(), 0);

    for(int i = 1, j = 0; i < p.size(); i++){
        while (0 < j && p[i] != p[j])
            j = table[j - 1];
        if (p[i] == p[j])
            table[i] = ++j;
    }

    for (int i = 0, j = 0; i < t.size(); i++) {
        while (0 < j && t[i] != p[j])
            j = table[j - 1];
        if (t[i] == p[j]) {
            if (j == p.size() - 1) {
                idx.push_back(i - p.size() + 2);
                answer++;
                j = table[j];
            } else {
                j++;
            }
        }
    }

    cout << answer << "\n";
    for (auto &c : idx)
        cout << c << " ";

    return 0;
}
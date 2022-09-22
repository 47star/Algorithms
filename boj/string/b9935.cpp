#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

typedef pair<int, int> track;

char a[1000001], b[63];
int n, m, i, l = 0, e = 0, bc[1000000], ec[1000000];
stack<pair<int, int>> s;

int main() {
    cin >> a >> b;

    n = strlen(a), m = strlen(b);

    if (m == 1) {
        for (int i = 0; i < n; i++)
            if (a[i] == b[0]) {
                bc[i]++;
                ec[i]++;
            }
    } else {
        for (int i = 0; i < n; i++){
            if (a[i] == b[0]) { 
                s.push(track(i, 1));
                continue;
            }

            while (!s.empty()) {
                track t = s.top();
                s.pop();

                if (a[i] != b[t.second]) {
                    while (!s.empty())
                        s.pop();
                    break;
                }

                t.second++;
                if (t.second == m) { 
                    bc[t.first]++; 
                    ec[i]++; 
                } else 
                    s.push(track(t.first, t.second));

                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        e += bc[i];

        if (e)
            a[i] = '*';
        else
            l++;

        e -= ec[i];
    }

    if (l) {
        for (int i = 0; i < n; i++)
            if (a[i] != '*')
                cout << a[i];
    } else
        cout << "FRULA";

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct doc {
    int index;
    int priority;
};

int main() {
    int c, i, n, idx, p, a;
    doc cd;
    vector<doc> q;
    scanf("%d", &c);

    while (c--) {
        scanf("%d %d", &n, &idx);

        for (i = 0; i < n; i++) {
            scanf("%d", &p);
            q.push_back(doc { i, p });
        }

        a = -1;
        while (++a <= q.size()) {
            for (i = 0; i + a < q.size(); i++) {
                if (q.at(a).priority < q.at(i + a).priority) {
                    q.push_back(q.at(a));
                    q.erase(q.begin() + a);
                    i = 0;
                }
            }
        }

        for (i = 0; i < n; i++) {
            if (q.at(i).index == idx) {
                printf("%d\n", i + 1);
                break;
            }
        }

        q.clear();
    }

    return 0;
}
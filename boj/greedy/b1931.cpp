#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Schedule {
    unsigned int start;
    unsigned int end;
};

bool compareByStart(Schedule a, Schedule b) {
    return a.start < b.start;
}

bool compareByEnd(Schedule a, Schedule b) {
    return a.end < b.end;
}

int main() {
    unsigned int n, i, s, e, c = 1;
    scanf("%u", &n);

    if (n == 1) {
        printf("1");
        return 0;
    }

    Schedule *schds = (Schedule*)malloc(n * sizeof(Schedule));

    for (i = 0; i < n; i++) {
        scanf("%u %u", &s, &e);
        schds[i] = Schedule { s, e };
    }

    sort(schds, schds + n, compareByStart);
    sort(schds, schds + n, compareByEnd);

    unsigned int cur = schds[0].end;
    for (i = 1; i < n; i++) {
        if (cur <= schds[i].start) {
            c++;
            cur = schds[i].end;
        }
    }

    printf("%u", c);

    return 0;
}
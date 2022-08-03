#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
	unsigned int n, i;
    short a, min, max;
    scanf("%u", &n);

    priority_queue<short, vector<short>, less<short>> maxq;
    priority_queue<short, vector<short>, greater<short>> minq;

    for (i = 0; i < n; i++) {
        scanf("%hd", &a);

        if (maxq.size() == minq.size())
            maxq.push(a);
        else
            minq.push(a);
        
        if (minq.size() != 0 && minq.top() < maxq.top()) {
            max = maxq.top();
            min = minq.top();
            maxq.pop();
            minq.pop();
            maxq.push(min);
            minq.push(max);
        }
        
        printf("%hd\n", maxq.top());
    }
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    unsigned short a;
    unsigned short b;
    int w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

unsigned short* find_parent(unsigned short** parent, unsigned short i) {
    if (i != (*parent)[i])
        (*parent)[i] = *find_parent(parent, (*parent)[i]);
    return &(*parent)[i];
}

int main() {
    unsigned short v, a, b;
    unsigned int i, e;
    int w;
    long cost = 0;

    scanf("%hu %ud", &v, &e);

    Edge* edges = (Edge*)malloc(e * sizeof(Edge));

    for (i = 0; i < e; i++) {
        scanf("%hu %hu %d", &a, &b, &w);
        edges[i] = Edge { a, b, w };
    }

    sort(edges, edges + e, compare);

    unsigned short* parent = (unsigned short*)malloc(v * sizeof(unsigned short));
    for (i = 0; i < v; i++) {
        parent[i] = i;
    }

    for (i = 0; i < e; i++) {
        a = *find_parent(&parent, edges[i].a);
        b = *find_parent(&parent, edges[i].b);
        if (a != b) {
            cost += edges[i].w;
            parent[a] = b;
        }
    }

    printf("%ld", cost);

    return 0;
}
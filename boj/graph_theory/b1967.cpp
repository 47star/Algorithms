#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    short node;
    signed char cost;
};

struct SearchedNode {
    short node;
    unsigned int cost;
};

SearchedNode dfs(vector<Node>** nodes, bool* visited, SearchedNode start) {
    visited[start.node] = true;
    SearchedNode res, max = SearchedNode { -1, start.cost };
    Node* current ;
    size_t len = nodes[start.node]->size();
    for (unsigned short i = 0; i < len; i++) {
        current = &nodes[start.node]->at(i);
        if (!visited[current->node]) {
            res = dfs(nodes, visited, SearchedNode { current->node, start.cost + current->cost });
            if (max.cost < res.cost)
                max = res;
        }
    }
    if (max.node == -1)
        return SearchedNode { start.node, start.cost };
    return max;
}

int main() {
    unsigned short v, i;
    short a, b;
    signed char c;
    scanf("%hu", &v);

    vector<Node>** nodes = (vector<Node>**)malloc(v * sizeof(size_t));
    bool* visited = (bool*)calloc(v, sizeof(bool));

    for (i = 0; i < v; i++) {
        nodes[i] = new vector<Node>;
    }

    for (i = 0; i < v - 1; i++) {
        scanf("%hd %hd %hhd", &a, &b, &c);
        nodes[--a]->push_back(Node { --b, c });
        nodes[b]->push_back(Node { a, c });
    }

    SearchedNode r = SearchedNode { 0, 0 };
    r = dfs(nodes, visited, r);
    r.cost = 0;
    free(visited);
    visited = (bool*)calloc(v, sizeof(bool));
    printf("%u", dfs(nodes, visited, r).cost);

    return 0;
}
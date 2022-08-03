#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int node;
    unsigned int cost;
};

Node dfs(vector<Node>** nodes, bool* visited, int node, unsigned int cost) {
    visited[node] = true;
    Node res, max = Node { -1, cost };
    size_t len = nodes[node]->size();
    Node* current;
    for (int i = 0; i < len; i++) {
        current = &nodes[node]->at(i);
        if (!visited[current->node]) {
            res = dfs(nodes, visited, current->node, current->cost + cost);
            if (max.cost < res.cost)
                max = res;
        }
    }
    if (max.node == -1)
        return Node { node, cost };
    return max;
}

int main() {
    int v, i, n, p;
    unsigned int c;
    scanf("%d", &v);

    bool* visited = (bool*)calloc(v, sizeof(bool));
    vector<Node>** nodes = (vector<Node>**)malloc(v * sizeof(vector<Node>*));

    for (i = 0; i < v; i++) {
        vector<Node>* paths = new vector<Node>;
        scanf("%d", &p);
        scanf("%d", &n);
        while (n != -1) {
            scanf("%u", &c);
            paths->push_back(Node { n - 1, c });
            scanf("%d", &n);
        }
        nodes[p - 1] = paths;
    }

    Node r = dfs(nodes, visited, 0, 0);
    free(visited);
    visited = (bool*)calloc(v, sizeof(bool));
    printf("%u", dfs(nodes, visited, r.node, 0).cost);

    return 0;
}
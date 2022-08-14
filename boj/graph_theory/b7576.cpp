#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Slot {
    short x, y;
};

short dx[] = { -1, 1, 0, 0 };
short dy[] = { 0, 0, -1, 1 };

int main() {
    short m, n, x, y, nx, ny;
    int worst = 0;
    char i;
    Slot slot;
    scanf("%hd %hd", &m, &n);

    int graph[1000][1000];
    queue<Slot> q;

    for (y = 0; y < n; y++)
        for (x = 0; x < m; x++) {
            scanf("%d", &graph[y][x]);
            if (graph[y][x] == 1)
                q.push({ x, y });
        }
    
    while (!q.empty()) {
        slot = q.front();
        q.pop();

        for (i = 0; i < 4; i++) {
            nx = slot.x + dx[i];
            ny = slot.y + dy[i];

            if (-1 < nx && -1 < ny && nx < m && ny < n && graph[ny][nx] == 0) {
                graph[ny][nx] = graph[slot.y][slot.x] + 1;
                q.push({ nx, ny });
            }
        }
    }

    for (y = 0; y < n; y++)
        for (x = 0; x < m; x++) {
            if (graph[y][x] == 0) {
                printf("-1");
                return 0;
            }
            if (worst < graph[y][x])
                worst = graph[y][x];
        }

    printf("%d", worst - 1);

    return 0;
}
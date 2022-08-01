#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    unsigned int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* back;
    size_t size;
};

int main() {
    unsigned short n, i;
    unsigned int a;
    char ins[5];

    scanf("%hu", &n);
    Queue queue = Queue { NULL, NULL, 0 };
    Node* m;

    for (i = 0; i < n; i++) {
        scanf("%s", &ins);

        if (strncmp(ins, "push", 4) == 0) {
            scanf("%u", &a);
            queue.size++;
            m = (Node*)malloc(sizeof(Node));
            *m = Node { a, NULL };
            if (queue.front == NULL)
                queue.front = m;
            if (queue.back != NULL)
                queue.back->next = m;
            queue.back = m;
        } else if (strncmp(ins, "pop", 3) == 0) {
            if (queue.front == NULL) {
                printf("-1\n");
                continue;
            }
            queue.size--;
            m = queue.front;
            printf("%u\n", m->data);
            if (queue.front == queue.back)
                queue.back = NULL;
            queue.front = m->next;
            free(m);
        } else if (strncmp(ins, "front", 5) == 0) {
            if (queue.front == NULL) {
                printf("-1\n");
                continue;
            }
            printf("%u\n", queue.front->data);
        } else if (strncmp(ins, "back", 4) == 0) {
            if (queue.back == NULL) {
                printf("-1\n");
                continue;
            }
            printf("%u\n", queue.back->data);
        } else if (strncmp(ins, "size", 4) == 0) {
            printf("%lu\n", queue.size);
        } else if (strncmp(ins, "empty", 5) == 0) {
            printf("%d\n", queue.front == NULL);
        }
    }

    return 0;
}
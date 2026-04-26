#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Standard Queue implementation
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) return -1;
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// BFS algorithm
void bfs(int adj[MAX][MAX], int vertices, int startNode) {
    struct Queue* q = createQueue();
    int visited[MAX] = {0}; // Track visited nodes to avoid cycles

    visited[startNode] = 1;
    enqueue(q, startNode);

    printf("BFS Traversal: ");

    while (!isEmpty(q)) {
        int currentNode = dequeue(q);
        printf("%d ", currentNode);

        for (int i = 0; i < vertices; i++) {
            // Check for adjacent and unvisited nodes
            if (adj[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices = 5;
    // Example Graph (Adjacency Matrix)
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    bfs(adj, vertices, 0); // Start BFS from node 0

    return 0;
}

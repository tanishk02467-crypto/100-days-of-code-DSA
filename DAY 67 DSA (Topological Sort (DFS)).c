#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjLists;
    int* visited;
};

int stack[100];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjLists = malloc(V * sizeof(struct Node*));
    graph->visited = calloc(V, sizeof(int));
    for (int i = 0; i < V; i++) graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void topologicalSortUtil(struct Graph* graph, int v) {
    graph->visited[v] = 1;

    struct Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int neighbor = temp->dest;
        if (!graph->visited[neighbor]) {
            topologicalSortUtil(graph, neighbor);
        }
        temp = temp->next;
    }

    push(v);
}

void topologicalSort(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        if (!graph->visited[i]) {
            topologicalSortUtil(graph, i);
        }
    }

    printf("Topological Ordering: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}

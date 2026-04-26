#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjLists;
};

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
    for (int i = 0; i < V; i++) graph->adjLists[i] = NULL;
    return graph;
}

void addDirectedEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

int isCyclicUtil(struct Graph* graph, int v, int visited[], int recStack[]) {
    if (!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;

        struct Node* temp = graph->adjLists[v];
        while (temp != NULL) {
            int neighbor = temp->dest;

            if (!visited[neighbor] && isCyclicUtil(graph, neighbor, visited, recStack))
                return 1;

            else if (recStack[neighbor])
                return 1;

            temp = temp->next;
        }
    }

    recStack[v] = 0;
    return 0;
}

int isCyclic(struct Graph* graph) {
    int* visited = calloc(graph->V, sizeof(int));
    int* recStack = calloc(graph->V, sizeof(int));

    for (int i = 0; i < graph->V; i++) {
        if (isCyclicUtil(graph, i, visited, recStack))
            return 1;
    }
    return 0;
}

int main() {
    struct Graph* graph = createGraph(4);
    addDirectedEdge(graph, 0, 1);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 2, 0); 
    addDirectedEdge(graph, 2, 3);

    if (isCyclic(graph)) printf("Graph contains a cycle\n");
    else printf("Graph is Acyclic\n");

    return 0;
}

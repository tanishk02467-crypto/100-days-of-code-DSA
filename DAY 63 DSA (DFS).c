#include <stdio.h>
#include <stdlib.h>

// Standard Node and Graph structures
struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjLists;
    int* visited; // Array to keep track of visited nodes
};

// Create a node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Initialize all as unvisited
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (Undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Recursive DFS Function
void DFS(struct Graph* graph, int vertex) {
    // 1. Mark the current node as visited
    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    // 2. Traverse all neighbors of the current vertex
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    while (temp != NULL) {
        int connectedVertex = temp->dest;

        // 3. If neighbor is not visited, recurse
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("DFS starting from vertex 2:\n");
    DFS(graph, 2); 

    return 0;
}

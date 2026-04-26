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

int isCyclicUtil(struct Graph* graph, int v, int parent) {
    graph->visited[v] = 1;

    struct Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int neighbor = temp->dest;

        if (!graph->visited[neighbor]) {
            if (isCyclicUtil(graph, neighbor, v))
                return 1;
        }

        else if (neighbor != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int isCyclic(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        if (!graph->visited[i]) {
            // Initial call: parent is -1
            if (isCyclicUtil(graph, i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V = 4;
    struct Graph* graph = createGraph(V);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0); 
    addEdge(graph, 2, 3);

    if (isCyclic(graph))
        printf("Graph contains a cycle\n");
    else
        printf("Graph doesn't contain a cycle\n");

    return 0;
}

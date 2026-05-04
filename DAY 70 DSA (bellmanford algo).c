#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

struct Edge {
    int u;
    int v;
    int w;
};


void bellmanFord(int n, int m, struct Edge edges[], int src) {
    long long *dist = (long long *)malloc(n * sizeof(long long));
    
    
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool hasNegativeCycle = false;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("Graph contains a negative weight cycle reachable from the source.\n");
    } else {
        printf("Vertex \t Distance from Source (%d)\n", src);
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) {
                printf("%d \t INF\n", i);
            } else {
                printf("%d \t %lld\n", i, dist[i]);
            }
        }
    }

    free(dist);
}

int main() {
    int n, m, src;
    
    printf("Enter the number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 1;

    struct Edge *edges = (struct Edge *)malloc(m * sizeof(struct Edge));

    printf("Enter edges (u v w) where edge goes from u to v with weight w:\n");
    for (int i = 0; i < m; i++) {
        if (scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w) != 3) {
            free(edges);
            return 1;
        }
    }

    printf("Enter the source vertex: ");
    if (scanf("%d", &src) != 1) {
        free(edges);
        return 1;
    }

    bellmanFord(n, m, edges, src);

    free(edges);
    return 0;
}

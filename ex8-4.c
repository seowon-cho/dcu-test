#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int n;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} graphType;

void createGraph(graphType* G) {
    if (!G) return;
    G->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            G->adjMatrix[i][j] = 0;
        }
    }
}

void insertVertex(graphType* G, int v) {
    if (!G || v < 0 || v >= MAX_VERTICES) return;
    if (v >= G->n) {
        G->n = v + 1;
    }
}

void insertEdge(graphType* G, int u, int v) {
    if (!G || u < 0 || u >= MAX_VERTICES || v < 0 || v >= MAX_VERTICES) return;
    G->adjMatrix[u][v] = 1;
    if (u >= G->n) G->n = u + 1;
    if (v >= G->n) G->n = v + 1;
}

void print_adjMatrix(graphType* G) {
    if (!G) return;
    printf("\nAdjacency matrix:\n");
    for (int i = 0; i < G->n; i++) {
        for (int j = 0; j < G->n; j++) {
            printf("%d ", G->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void BFS_adjMatrix(graphType* G, int start) {
    if (!G || start < 0 || start >= G->n) return;
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS traversal from vertex %d:\n", start);
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int w = 0; w < G->n; w++) {
            if (G->adjMatrix[v][w] && !visited[w]) {
                visited[w] = 1;
                queue[rear++] = w;
            }
        }
    }
    printf("\n");
}

int main(void) {
    graphType* G = (graphType*)malloc(sizeof(graphType));
    if (!G) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    createGraph(G);
    for (int i = 0; i < 6; i++) {
        insertVertex(G, i);
    }

    insertEdge(G, 0, 1);
    insertEdge(G, 0, 2);
    insertEdge(G, 1, 3);
    insertEdge(G, 1, 4);
    insertEdge(G, 2, 4);
    insertEdge(G, 3, 5);
    insertEdge(G, 4, 5);

    print_adjMatrix(G);
    BFS_adjMatrix(G, 0);

    getchar();
    free(G);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

typedef struct {
    int n;
    GraphNode* adjList[MAX_VERTICES];
} graphType;

static void dfs_recursive(graphType* G, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (GraphNode* p = G->adjList[v]; p; p = p->next) {
        if (!visited[p->vertex]) {
            dfs_recursive(G, p->vertex, visited);
        }
    }
}

void createGraph(graphType* G) {
    if (!G) return;
    G->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        G->adjList[i] = NULL;
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
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    if (!node) return;
    node->vertex = v;
    node->next = G->adjList[u];
    G->adjList[u] = node;
    if (u >= G->n) {
        G->n = u + 1;
    }
    if (v >= G->n) {
        G->n = v + 1;
    }
}

void print_adjList(graphType* G) {
    if (!G) return;
    for (int i = 0; i < G->n; i++) {
        printf("\n%d :", i);
        for (GraphNode* p = G->adjList[i]; p; p = p->next) {
            printf(" %d", p->vertex);
        }
    }
}

void DFS_adjList(graphType* G, int start) {
    if (!G || start < 0 || start >= G->n) return;
    int visited[MAX_VERTICES] = {0};
    dfs_recursive(G, start, visited);
}

int main(void) {
    int i;
    graphType* G9 = (graphType*)malloc(sizeof(graphType));
    if (!G9) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    createGraph(G9);
    for (i = 0; i < 7; i++) {
        insertVertex(G9, i);
    }
    insertEdge(G9, 0, 2);
    insertEdge(G9, 0, 1);
    insertEdge(G9, 1, 4);
    insertEdge(G9, 1, 3);
    insertEdge(G9, 1, 0);
    insertEdge(G9, 2, 4);
    insertEdge(G9, 2, 0);
    insertEdge(G9, 3, 6);
    insertEdge(G9, 3, 1);
    insertEdge(G9, 4, 6);
    insertEdge(G9, 4, 2);
    insertEdge(G9, 4, 1);
    insertEdge(G9, 5, 6);
    insertEdge(G9, 6, 5);
    insertEdge(G9, 6, 4);
    insertEdge(G9, 6, 3);

    printf("\n G9의 인접 리스트");
    print_adjList(G9);

    printf("\n\n//////////////\n\n깊이 우선 탐색 >> ");
    DFS_adjList(G9, 0);
    printf("\n");

    getchar();
    return 0;
}

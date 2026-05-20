#include <stdio.h>
#include "adjMatrix.h"

int main(void) {
    int i;
    graphType* G1 = (graphType*)malloc(sizeof(graphType));
    graphType* G2 = (graphType*)malloc(sizeof(graphType));
    graphType* G3 = (graphType*)malloc(sizeof(graphType));
    graphType* G4 = (graphType*)malloc(sizeof(graphType));

    createGraph(G1);
    for (i = 0; i < 4; i++)
		insertVertex(G1, i);
	insertEdge(G1, 0, 3);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 3, 2);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 0);

    createGraph(G2);
	for (i = 0; i < 3; i++)
		insertVertex(G2, i);	
	insertEdge(G2, 0, 2);
	insertEdge(G2, 0, 1);
	insertEdge(G2, 1, 2);
	insertEdge(G2, 1, 0);
	insertEdge(G2, 2, 1);
	insertEdge(G2, 2, 0);

    createGraph(G3);
	for (i = 0; i < 4; i++)
		insertVertex(G3, i);	
	insertEdge(G3, 0, 3);
	insertEdge(G3, 0, 1);
	insertEdge(G3, 1, 3);
	insertEdge(G3, 1, 2);
	insertEdge(G3, 2, 3);

    createGraph(G4);
	for (i = 0; i < 3; i++)
		insertVertex(G4, i);
	insertEdge(G4, 0, 2);
	insertEdge(G4, 0, 1);
	insertEdge(G4, 1, 2);
	insertEdge(G4, 1, 0);
	
    printf("\n G1의 인접 행렬");
	print_adjMatrix(G1);

	printf("\n\n G2의 인접 행렬");
	print_adjMatrix(G2);

	printf("\n\n G3의 인접 행렬");
	print_adjMatrix(G3);
	
	printf("\n\n G4의 인접 행렬");
	print_adjMatrix(G4);

	getchar();  return 0;
}

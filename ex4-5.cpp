#include "LinkedPoly.h"

int main(void) {
	ListHead* A, * B, * C;

	
	A = createLinkedList();
	B = createLinkedList();
	C = createLinkedList();

	appendTerm(A, 4, 3);	
	appendTerm(A, 3, 2);	
	appendTerm(A, 5, 1);	
	printf("\n A(x) =");
	printPoly(A);			

	appendTerm(B, 3, 4);	
	appendTerm(B, 1, 3);	
	appendTerm(B, 2, 1);	
	appendTerm(B, 1, 0);	
	printf("\n B(x) =");

	printPoly(B);			
	addPoly(A, B, C);		
	printf("\n C(x) =");
	printPoly(C);			

	getchar();  return 0;
}
#include "dft.h"

GraphPtr newGraph(int n) {
	GraphPtr p;
	
	if(n > MaxVertices) {
		printf("\nToo big. Only %d vertices allowed.\n", MaxVertices);
		exit(1);
	}
	p = (GraphPtr) malloc(sizeof(Graph));
	p->numV = n;
	
	return p;
} // end newGraph

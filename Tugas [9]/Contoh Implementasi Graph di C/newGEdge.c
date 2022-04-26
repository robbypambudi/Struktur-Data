#include "dft.h"

GEdgePtr newGEdge(int c, int w) {
	// return a pointer to a new GEdge node
	GEdgePtr p;
	
	p = (GEdgePtr) malloc(sizeof(GEdge));
	p->child = c;
	p->weight = w;
	p->nextEdge = NULL;
	
	return p;
} 

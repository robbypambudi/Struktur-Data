#include "dft.h"

GraphPtr newGraph(int n)
{
	GraphPtr p; // pointer to Graph

	if (n > MaxVertices)
	{ // cek jumlah vertex
		printf("\nToo big. Only %d vertices allowed.\n", MaxVertices);
		exit(1);
	}
	p = (GraphPtr)malloc(sizeof(Graph)); // alokasi memori
	p->numV = n;						 // jumlah vertex

	return p; // return pointer to Graph
} // end newGraph

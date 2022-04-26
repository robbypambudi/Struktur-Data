// Dibuat oleh Robby Ulung Pambudi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dft.h"

int main()
{
	int numVertices; //
	GraphPtr G;
	FILE *in = fopen("graph3.in", "r");

	fscanf(in, "%d", &numVertices);
	G = newGraph(numVertices);
	buildGraph(in, G);
	printGraph(G);
	printf("\n");
	print_inDegree(G);
	printf("\n");
	print_outDegree(G);
	fclose(in);

	return 0;
} // end main

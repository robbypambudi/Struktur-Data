#include "dft.h"

int main()
{
	int numVertices;
	GraphPtr G;
	FILE *in = fopen("graph3.in", "r");

	fscanf(in, "%d", &numVertices);
	G = newGraph(numVertices);
	buildGraph(in, G);
	printGraph(G);
	depthFirstTraversal(G, 1);
	printPath(G, "A");
	printPath(G, "B");
	printPath(G, "C");
	printPath(G, "D");
	printPath(G, "E");
	printPath(G, "F");
	printPath(G, "G");
	fclose(in);

	return 0;
} // end main

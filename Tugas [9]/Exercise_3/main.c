/*
	Robby Ulung Pambudi
	5025211042
*/

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

	Graph *g = createGraph(7); // inisiasi graph

	// inisiasi mulai dari A = 0
	addEdge(g, 0, 2, 65);
	addEdge(g, 0, 3, 15);
	addEdge(g, 0, 4, 55);

	// inisiasi mulai dari B = 1
	addEdge(g, 1, 2, 20);
	addEdge(g, 1, 4, 10);
	addEdge(g, 1, 5, 30);
	addEdge(g, 1, 6, 45);

	// inisiasi mulai dari C = 2
	addEdge(g, 2, 3, 70);
	addEdge(g, 2, 4, 60);
	addEdge(g, 2, 5, 40);

	// inisisasi mulai dari D = 3
	addEdge(g, 3, 4, 50);
	addEdge(g, 3, 5, 35);

	// inisiasi mulai dari E = 4
	addEdge(g, 4, 6, 25);

	printList(g);	// pemanggilan fungsi untuk mencetak list graph
	printMatrix(g); // pemanggilan fungsi untuk mencetak matrix graph
	printf("\nDepth First Traversal\n");
	DFT(g, 0); // Pemanggilan fungsi untuk depth first traversal
	printf("\nBreadth First Travesal \n");
	BFT(g, 0); // Pemanggilan fungsi untuk breadth first traversal

	return 0;
}

/*
	Nama   = Katarina Inezita Prambudi
	NRP    = 5025211148
	Kelas  = Struktur Data E

	Main Function
*/
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{

	Graph *g = createGraph(7); // inisiasi graph

	// inisiasi mulai dari A = 0
	addEdge(g, 0, 2);
	addEdge(g, 0, 3);
	addEdge(g, 0, 4);

	// inisiasi mulai dari B = 1
	addEdge(g, 1, 2);
	addEdge(g, 1, 4);
	addEdge(g, 1, 5);
	addEdge(g, 1, 6);

	// inisiasi mulai dari C = 2
	addEdge(g, 2, 3);
	addEdge(g, 2, 4);
	addEdge(g, 2, 5);

	// inisisasi mulai dari D = 3
	addEdge(g, 3, 4);
	addEdge(g, 3, 5);

	// inisiasi mulai dari E = 4
	addEdge(g, 4, 6);

	printList(g);

	char i; // inisiasi variable character
	// melakukan looping selama i tidak sama dengan 48
	while (i != 48)
	{
		printf("\n DFT | Start at ");
		scanf("%c", &i);
		if (i == 32 || i == 10)
			scanf("%c", &i);
		printf(" %c : ", i);
		DFT(g, 7, i - 65); // Pemanggilan fungsi DFT
	}
	return 0;
}

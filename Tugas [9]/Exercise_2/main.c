/*
Dibuat oleh : Robby Ulung Pambudi
NRP 		: 5025211042

Dibuat pada 		: 25 April
Last Modification 	: 26 April 2022

Fungsi main untuk menjalankan program

*/

#include "dft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int numVertices;
	GraphPtr G;

	// Membaca jumlah vertex

	FILE *in = fopen("graph3.in", "r");
	fscanf(in, "%d", &numVertices);

	// Membuat graph
	G = newGraph(numVertices);
	buildGraph(in, G);

	// DFT
	depthFirstTraversal(G, 4);
	fclose(in);

	// Selesai
	return 0;
} // end main

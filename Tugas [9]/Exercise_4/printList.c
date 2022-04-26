
#include "header.h"

void printList(Graph *g)
{
	int i;
	// Melakukan loop sebanyak jumlah vertices
	for (i = 0; i < g->Vertices; ++i)
	{
		// Inisiasi variable untuk mendapatkan adjacency list dari setiap vertices
		AjlistNode *crawl = g->array[i].head;

		// menampilkan output
		printf("\n ==== Adjacency List Of Vertices %c ==== \n head ", i + 65);

		// melakukan loop hinggal crawl bernilai NULL
		while (crawl)
		{
			printf(" => %c ", crawl->id + 65);
			crawl = crawl->next;
		}
		printf("\n");
	}
}

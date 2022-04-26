
#include "header.h"

void DFT(Graph *g, int Vertices)
{
	// inisiasi variable temp
	AjlistNode *temp = g->array[Vertices].head;

	// menandakan vertices telah dikunjungi
	g->visitedDFT[Vertices] = 1;

	// menampilkan nama vertices
	printf("%c ", Vertices + 65);

	// melakukan loop untuk menjalankan traversal
	while (temp != NULL)
	{
		// inisiasi variable connect dengan nilai temp
		int connect = temp->id;

		if (g->visitedDFT[connect] == 0)
		{
			DFT(g, connect);
		}
		temp = temp->next;
	}
}

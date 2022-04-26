
#include "header.h"

void printMatrix(Graph *g)
{
	printf("\n==== Adjacency Matrix ====\n");

	int i;
	// melakukan loop secara mendatar
	for (i = 0; i < g->Vertices; i++)
	{
		printf("\t%c", i + 65);
	}
	printf("\n");

	int j;
	// melakukan loop untuk menampilkan weight
	for (j = 0; j < g->Vertices; j++)
	{
		// melakukan loop secara menurun
		printf("  %c  ", j + 65);
		int start = 0;

		AjlistNode *crawl = g->array[j].head;

		while (start < g->Vertices)
		{
			if (start == j)
			{
				// ketika matrix berada pada posisi yang sama
				printf("\t0");
				start++;
			}
			else if (crawl->id == start)
			{
				printf("\t%d", crawl->weight);
				if (crawl->next)
				{
					crawl = crawl->next;
				}
				start++;
			}
			else
			{
				printf("\t-1");
				start++;
			}
		}
		printf("\n");
	}
}

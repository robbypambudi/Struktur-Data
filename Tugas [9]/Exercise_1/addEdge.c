#include "dft.h"

void addEdge(char x[], char y[], int weight, GraphPtr G)
{
	// add an edge x -> y with a given weight
	int j, k;
	GEdgePtr ep, prev, curr;

	// find x in the list of nodes; its location is j;
	for (j = 1; j <= G->numV; j++)
		if (strcmp(x, G->vertex[j].id) == 0)
			break;

	// find y in the list of nodes; its location is k;
	for (k = 1; k <= G->numV; k++)
		if (strcmp(y, G->vertex[k].id) == 0)
			break;

	if (j > G->numV || k > G->numV)
	{
		printf("No such edge: %s->%s\n", x, y);
		exit(1);
	}

	ep = newGEdge(k, weight); // create edge vertex

	// add it to the list of edges, possible empty, from x;
	// it is added so that the list is in order by vertex id
	prev = curr = G->vertex[j].firstEdge;
	while (curr != NULL && strcmp(y, G->vertex[curr->child].id) > 0)
	{
		prev = curr;
		curr = curr->nextEdge;
	}

	if (prev == curr)
	{
		ep->nextEdge = G->vertex[j].firstEdge;
		G->vertex[j].firstEdge = ep;
	}
	else
	{
		ep->nextEdge = curr;
		prev->nextEdge = ep;
	}
} // end addEdge

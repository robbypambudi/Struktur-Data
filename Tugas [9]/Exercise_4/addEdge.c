
#include "header.h"
void addEdge(Graph *g, int source, int destination)
{

	// inisiasi check
	AjlistNode *check = NULL;

	// inisiasi newgraph
	AjlistNode *newgraph = newGraph(destination);

	// jika belum memiliki degree
	if (g->array[source].head == NULL)
	{

		// newgraph akan dimasukkan sebagai head
		g->array[source].head = newgraph;

		// Jika belum memiliki degree
	}
	else
	{

		check = g->array[source].head;
		while (check->next != NULL)
		{
			check = check->next;
		}
		check->next = newgraph;
	}

	// Penambahan edge untuk undirected graph
	newgraph = newGraph(source);
	if (g->array[destination].head == NULL)
	{
		g->array[destination].head = newgraph;
	}
	else
	{
		check = g->array[destination].head;
		while (check->next != NULL)
		{
			check = check->next;
		}
		check->next = newgraph;
	}
}


#include "header.h"

AjlistNode *newGraph(int id, int weight)
{
	// inisiasi newgraph
	AjlistNode *newgraph = (AjlistNode *)malloc(sizeof(AjlistNode));

	// memasukkan data pada newgraph
	newgraph->id = id;
	newgraph->weight = weight;
	newgraph->next = NULL;

	return newgraph;
}

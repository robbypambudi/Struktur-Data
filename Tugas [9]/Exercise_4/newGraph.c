

#include "header.h"

AjlistNode *newGraph(int id)
{
	// inisiasi newgraph
	AjlistNode *newgraph = (AjlistNode *)malloc(sizeof(AjlistNode));

	// memasukkan data pada newgraph
	newgraph->id = id;
	newgraph->next = NULL;

	return newgraph;
}

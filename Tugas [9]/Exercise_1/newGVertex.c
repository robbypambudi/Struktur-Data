#include "dft.h"

GVertex newGVertex(char name[])
{
	GVertex temp; // create a vertex node

	strcpy(temp.id, name); // copy the name into id
	temp.firstEdge = NULL; // no edges yet

	return temp; // return the new vertex node
}

#include "dft.h"

GVertex newGVertex(char name[]) {
	GVertex temp;
	
	strcpy(temp.id, name);
	temp.firstEdge = NULL;
	
	return temp;
}

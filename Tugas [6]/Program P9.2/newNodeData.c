#include "header.h"

NodeData newNodeData(char str[], int n)
{
    NodeData temp;
    strcpy(temp.word, str);
    temp.freq = n;
    return temp;
} // end newNodeData
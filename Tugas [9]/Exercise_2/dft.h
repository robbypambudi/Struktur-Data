/*
Dibuat oleh : Robby Ulung Pambudi
NRP 		: 5025211042

Dibuat pada 		: 25 April
Last Modification 	: 26 April 2022

Deskripsi :

Give the depth-first and breadth-first traversals of the graph starting at D. Edges of a
node are processed in alphabetical order.
Assume that a depth-first traversal is performed starting at D and that edges of a node
are processed in alphabetical order. Indicate the discovery and finish times for each
node and label each edge with T (tree edge), B (back edge), F (forward edge) or C (cross
edge), according to its type.


Input :
7
A B C D E F G
A 0
B 3
A 0
C 0
E 0
C 1
A 0
D 3
B 0
E 0
F 0
E 2
C 0
G 0
F 2
E 0
G 0
G 1
C 0

* catatan
0 berarti tidak ada width atau tidak ada outDegree


Output  :

Depth-first traversal starting from D
D B A C E G F
Tree edge :  D -> B
Tree edge :  B -> A
Tree edge :  B -> C
Cross edge :  C -> A
Tree edge :  B -> E
Cross edge :  E -> C
Tree edge :  E -> G
Cross edge :  G -> C
Cross edge :  D -> E
Tree edge :  D -> F
Cross edge :  F -> E
Cross edge :  F -> G
*/

#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#define MaxWordSize 20
#define MaxVertices 50

#define White 'w'
#define Gray 'g'
#define Black 'b'

typedef struct
{
	int nv; /* index of a graph vertex */
} QueueData;

typedef struct node
{
	QueueData data;
	struct node *next;
} Node, *NodePtr;

typedef struct qType
{
	NodePtr head, tail;
} QueueType, *Queue;

typedef struct gEdge
{
	int child, weight; /* 'child' is the location of the child vertex */
	struct gEdge *nextEdge;
} GEdge, *GEdgePtr;

typedef struct
{
	char id[MaxWordSize + 1], colour;
	int parent, cost, discover, finish, inDegree;
	GEdgePtr firstEdge;
} GVertex;

typedef struct graph
{
	int numV;
	GVertex vertex[MaxVertices + 1];
} Graph, *GraphPtr;

Queue initQueue();
int emptyQueue(Queue);
void enQueue(Queue, QueueData);
QueueData deQueue(Queue);
QueueData newQueueData(int);
void buildGraph(FILE *, GraphPtr);
GraphPtr newGraph(int);
void depthFirstTraversal(GraphPtr, int);
void breadthFirstTraversal(GraphPtr, int);
void printGraph(GraphPtr);
void printPath(GraphPtr, char[]);
GVertex newGVertex(char[]);
void addEdge(char[], char[], int, GraphPtr);
void followPath(GraphPtr, int);
GEdgePtr newGEdge(int c, int w);
void dfTraverse(GraphPtr G, int s);
void dfTraverse2(GraphPtr G, int s);

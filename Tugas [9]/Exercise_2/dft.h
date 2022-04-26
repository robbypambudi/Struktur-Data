#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

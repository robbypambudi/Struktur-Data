
#ifndef DFT_H
#define DFT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

// Robby Ulung Pambudi
// 5025211042
// Created At : 23 - 4 - 2022

/*
Deskripsi :
	Write functions which, given the name of a node, returns the in-degree and out-degree
	of a node
*/

/*
Penyelesaian :
	1.Scan Number of Vertex
	2. Scan Vertex
	3. Scan Number of Edges
	4. Scan Edges
	5. Build Graph
	6. Print In-degree
	7. Print Out-degree
*/

// Input
/*
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
*/

// Output
/*
	Print Verteks: A B C D E F G
	In-degree:
	A: B C
	B: D
	C: B E G
	D:
	E: B D F
	F: D
	G: E F

	Out-degree:
	A:
	B: A C E
	C: A
	D: B E F
	E: C G
	F: E G
	G: C
*/
#define MaxWordSize 20
#define MaxVertices 50

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

// Prototypes
Queue initQueue();							 // Initialize Queue
int emptyQueue(Queue);						 // Check if Queue is empty
void enQueue(Queue, QueueData);				 // Enqueue
QueueData deQueue(Queue);					 // Dequeue
QueueData newQueueData(int);				 // Create new QueueData
void buildGraph(FILE *, GraphPtr);			 // Build Graph
GraphPtr newGraph(int);						 // Create new Graph
void printGraph(GraphPtr);					 // Print Graph
GVertex newGVertex(char[]);					 // Create new GVertex
void addEdge(char[], char[], int, GraphPtr); // Add Edge
void followPath(GraphPtr, int);				 // Follow Path
GEdgePtr newGEdge(int c, int w);			 // Create new GEdge
void dfTraverse(GraphPtr G, int s);			 // Depth First Traversal
void print_outDegree(GraphPtr G);			 // Print Out-degree
void print_inDegree(GraphPtr G);			 // Print In-degree

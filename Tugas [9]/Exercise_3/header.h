/*
	Robby Ulung Pambudi
	5025211042

	Give the adjacency matrix and list representation of the graph.
	Give the depth-first and breadth-first traversals atarting at A. Edges of a node are
	processed in alphabetical order.
*/

// Library
#ifndef _HEADER_H_
#define _HEADER_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#endif

// Definisi tipe data struct untuk adjacency list node
typedef struct AjlistNode_t
{
	int id;
	int weight;
	struct AjlistNode_t *next;
} AjlistNode;

// Definisi tipe data struct untuk adjacency list
typedef struct Ajlist_t
{
	struct AjlistNode_t *head;
} Ajlist;

// Definisi tipe data struct untuk graph
typedef struct
{
	int Vertices;
	int *visitedDFT;
	int *visitedBFT;
	struct Ajlist_t *array;
} Graph;

// Definisi tipe data struct untuk Queue Node
typedef struct queueNode_t
{
	int data;
	struct queueNode_t *next;
} QueueNode;

// Definisi tipe data struct untuk Queue
typedef struct queue_t
{
	QueueNode *_front,
		*_rear;
	unsigned _size;
} Queue;

// Deklarasi Fungsi
void queue_init(Queue *);			  // Fungsi untuk menginisialisasi queue
bool queue_isEmpty(Queue *);		  // Fungsi untuk melakukan pengecekan apakah queue kosong atau tidak
void queue_push(Queue *, int);		  // Fungsi untuk memasukkan data ke queue
void queue_pop(Queue *);			  // Fungsi untuk menghapus data pada queue
int queue_front(Queue *);			  // Fungsi untuk mendapatkan data paling depan pada queue
Graph *createGraph(int);			  // Fungsi untuk membuat graph
AjlistNode *newGraph(int, int);		  // Fungsi untuk membuat adjacency list node baru
void printMatrix(Graph *);			  // Fungsi untuk mencetak graph berupa matrix
void printList(Graph *);			  // Fungsi untuk mencetak graph berupa list
void addEdge(Graph *, int, int, int); // Fungsi untuk membuat sebuah edge
void DFT(Graph *, int);				  // Fungsi untuk melakukan Depth First Traversal
void BFT(Graph *, int);				  // Fungsi untuk melakukan Breadth First Traversal

/*
	Nama   = Robby Ulung pambudi
	NRP    = 5025211042

	Write a non-recursive function for performing depth-first traversal on a graph
*/

#ifndef _HEADER_H
#define _HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#endif

// Definisi tipe data struct untuk adjacency list node
typedef struct AjlistNode_t
{
	int id;
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
	struct Ajlist_t *array;
} Graph;

// Definisi tipe data struct untuk Stack Node
typedef struct stackNode_t
{
	int data;
	struct stackNode_t *next;
} StackNode;

// Definisi tipe data struct untuk Queue
typedef struct stack_t
{
	StackNode *_top;
	unsigned _size;
} Stack;

// Deklarasi Fungsi
void stack_init(Stack *stack);			  // Fungsi untuk menginisialisasi stack
bool stack_isEmpty(Stack *stack);		  // Fungsi untuk melakukan pengecekan apakah stack kosong atau tidak
void stack_push(Stack *stack, int value); // Fungsi untuk memasukkan data ke stack
void stack_pop(Stack *stack);			  // Fungsi untuk menghapus data pada stack
Graph *createGraph(int);				  // Fungsi untuk membuat graph
AjlistNode *newGraph(int);				  // Fungsi untuk membuat adjacency list node baru
void printList(Graph *);				  // Fungsi untuk mencetak graph berupa list
void DFT(Graph *, int, int);			  // Fungsi untuk melakukan Depth First Traversal
int valueCheck(int *, int, int);		  // Fungsi untuk mengecek apakah nilai sudah dicetak atau belum dalam DFT
void addEdge(Graph *, int, int);		  // Fungsi untuk membuat sebuah edge

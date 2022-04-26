
#include "header.h"
void BFT(Graph *g, int Vertices)
{
	// inisiasi queue
	Queue myQueue;
	queue_init(&myQueue);

	// menandakan vertices telah dikunjungi
	g->visitedBFT[Vertices] = 1;

	// memasukkan vertices ke dalam queue
	queue_push(&myQueue, Vertices);

	// melakukan looping selama queue tidak NULL
	while (!queue_isEmpty(&myQueue))
	{
		int curr = queue_front(&myQueue);
		queue_pop(&myQueue);

		printf("%c ", curr + 65);

		AjlistNode *temp = g->array[curr].head;
		while (temp)
		{
			int adj = temp->id;

			if (g->visitedBFT[adj] == 0)
			{
				queue_push(&myQueue, adj);
				g->visitedBFT[adj] = 1;
			}
			temp = temp->next;
		}
	}
}

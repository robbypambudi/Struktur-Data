
#include "header.h"

void DFT(Graph *g, int Vertices, int start)
{

	// inisiasi variable temp dengan tipe data AjlistNode
	AjlistNode *temp;

	// inisiasi variable penanda node yang telah dicetak
	int flag = 0;

	// inisiasi variable yang berisi nilai dari sebuah node yang telah dicetak
	int arr[Vertices];

	// inisiasi stack
	Stack myStack;
	stack_init(&myStack);

	// Nilai pertama
	// Menambahkan nilai kedalam stack
	arr[flag] = start;
	// Mencetak nilai
	printf("%c ", start + 65);
	// Menambah flag dengan 1
	flag++;
	// memasukkan nilai ke dalam stack
	stack_push(&myStack, start);
	// mengubah temp ke graph array dengan index nilai sebelumnya
	temp = g->array[start].head;

	// Melakukan looping hingga semua nilai telah dicetak
	while (flag != Vertices)
	{
		// Ketika nilai belum pernah dicetak
		if (temp != NULL && valueCheck(arr, temp->id, flag) == 0)
		{
			// menambahkan nilai kedalam stack
			arr[flag] = temp->id;
			// Mencetak nilai
			printf(" => %c", temp->id + 65);
			// menambah flag dengan 1
			flag++;
			// Memasukkan nilai kedalam stack
			stack_push(&myStack, temp->id);
			// mengubah temp ke graph array dengan index nilai sebelumnya
			temp = g->array[temp->id].head;
		}
		// ketika nilai sudah pernah di cetak
		else if (temp != NULL && valueCheck(arr, temp->id, flag) == 1)
		{
			temp = temp->next; // lanjut ke node berikutnya
							   // ketika node telah kosong
		}
		else if (temp == NULL)
		{
			// kembali ke array dengan index nilai sebelumnya
			temp = g->array[myStack._top->data].head;
			// menghapus data pada stack
			stack_pop(&myStack);
		}
	}
	printf("\n");
}

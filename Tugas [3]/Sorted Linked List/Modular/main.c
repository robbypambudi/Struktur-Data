#include "header.h" // Header file

int main()
{
	void printList(NodePtr);		  // Fungsi untuk mencetak linked list
	NodePtr addInPlace(NodePtr, int); // Fungsi untuk menambahkan node baru ke linked list secara ascending
	int n;							  // Variabel pembantu untuk validasi input
	NodePtr top = NULL;				  // Variabel top ini diinisialisasi Null
	if (scanf("%d", &n) != 1)		  // Validasi input
		n = 0;						  // Jika input tidak valid, n diinisialisasi 0
	while (n != 0)
	{							  // Ketika n tidak 0
		top = addInPlace(top, n); // top diinisialisasi dengan fungsi addInPlace
		if (scanf("%d", &n) != 1) // Validasi input
			n = 0;				  // Jika input tidak valid, n diinisialisasi 0
	}
	printList(top); // Mencetak linked list
} // end main
#include "header.h" // include header file

int main()
{

	NodePtr A, B; // deklarasi pointer A dan B
	printf("Enter numbers for the first list (0 to end)\n");
	A = makeList(); // memanggil fungsi makeList untuk membuat list A
	printf("Enter numbers for the second list (0 to end)\n");
	B = makeList(); // memanggil fungsi makeList untuk membuat list B
	printf("\nThe merged list is\n");
	printList(merge(A, B)); // memanggil fungsi merge untuk menggabungkan list A dan B
} // end main
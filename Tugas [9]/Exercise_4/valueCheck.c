
#include "header.h"

int valueCheck(int *array, int value, int max)
{
	int i;
	for (i = 0; i < max; i++)
	{
		if (array[i] == value)
		{
			return 1;
		}
	}
	return 0;
}

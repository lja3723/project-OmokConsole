#include "omok.h"

void omok_start()
{
	
}

int array_sum_int(int arr[], int len)
{
	int sum=0;
	for (int i = 0; i < len; i++)
		sum += i;
	return sum;
}

void array_print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}
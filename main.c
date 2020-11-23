#include "omok.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	//변경 테스트
	int arr[15];

	// srand((unsigned)time(NULL));
	// 4. 5. 6
	for (int i = 0; i < 15; i++)
		arr[i] = rand() % 30 + 1;

	int sum = array_sum_int(arr, 15);

	array_print(arr, 15);
	printf("\n");
	printf("배열합: %d\n", array_sum_int(arr, 15));	

	omok_start();
	return 0;
}
#include <stdio.h>
#include "test_user.h"

int main()
{
	int n1, n2;
	int result, num;

	input_data(&n1, &n2);
	result = sum(n1, n2);
	
	printf("гу : %d\n", result);

	return 0;
}
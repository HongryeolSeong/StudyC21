#include <stdio.h>

void swap_ptr(char** ppa, char** ppb);

int main()
{
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);
	printf("pa -> %u, pb -> %u\n", pa, pb);
	printf("&pa -> %u, &pb -> %u\n", &pa, &pb);
	swap_ptr(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);

	return 0;
}

void swap_ptr(char** ppa, char** ppb)
{
	char* pt;

	printf("&ppa -> %u, &ppb -> %u\n", &ppa, &ppb);
	printf("ppa -> %u, ppb -> %u\n", ppa, ppb);
	printf("*ppa -> %u, *ppb -> %u\n", *ppa, *ppb);


	pt = *ppa; // pt에 &pa를 입력
	*ppa = *ppb; // &pa에 &pb를 입력
	*ppb = pt; // &pb에 pt(&pa)를 입력

	return 0;
}
#include<stdio.h>
#include<string.h>

int main()
{
	int a[100];
	int b[100];
	int i = 0;
	for (i = 0; i < 100; i++) {
		a[i] = i;
	}
	memset(b, 0, sizeof(b));
	for (i = 0; i < 100; i++) {
		printf("%d ",b[i]);
	}
	printf("\n");
	memcpy(b, a, sizeof(a));
	for (i = 0; i < 100; i++) {
		printf("%d ",b[i]);
	}
	printf("\n");
	printf("size of pointer a is %d\n", sizeof(a));	
	return 0;
}

#include <libc.h>

int SumOf(int a[], int size)
{
	int i , sum = 0;
	for (i = 0; i < size ; i++)
		sum += a[i];
	return sum;
}
int main()
{
	int a[] = {1,2,3,4,5};
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d\n", size);
	int sum;
	sum = SumOf(a, size);
	printf("sum :%d", sum);
	
}
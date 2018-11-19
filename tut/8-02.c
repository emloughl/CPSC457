// Change main function to this:

#include <stdio.h>

#define num_loops 20000000

long long sum = 0;

void counting(int offset)
{
	for (long long i=0; i<num_loops; i++)
		sum+=offset;
}

int main()
{
	counting(1);
	counting(-1);
	printf("Sum = %lld\n", sum);

	return(0);

}

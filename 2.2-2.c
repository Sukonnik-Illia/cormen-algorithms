/*
Consider sorting n numbers stored in array A by first finding the smallest
element of A and exchanging it with element in A[1]. Then find the second
smallest element of A, and exchange it with A[2]. Continue in this manner for
the firs n-1 elements of A. Write pseudocode for this algorithm, which is known
as selection sort. What loop invariant does this algorithm maintain? Why does it
need to run for only the first n-1 elements, rather than for all n elements?
Give the best-case and worst-case running times of selection sort in θ-notation
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 10

main()
{
	int i, n, tmp, smallest_position;
	int A[LEN];

	/* initialize array with random numbers */
	for (i=0; i < LEN; i++)
		A[i] = rand();

	for (i=0; i < LEN; i++)
		printf("%d\n",A[i]);
	printf("\n");


	for(i=0; i < LEN-1; i++) {
		smallest_position = i;
		/* find smallest in right side */
		for(n=i; n < LEN; n++) {
			if(A[n] < A[smallest_position]) {
				smallest_position = n;
			}
		}

		tmp = A[i];
		A[i] = A[smallest_position];
		A[smallest_position] = tmp;

	}

	for (i=0; i < LEN; i++)
		printf("%d\n", A[i]);
}

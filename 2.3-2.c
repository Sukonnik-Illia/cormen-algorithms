/*
Rewrite the Merge procedure so that it does not use sentinels, instead
stopping once either array L or R has had all its elements copied back
to A and then copying the remainder of the other array back into A
*/

#include <stdio.h>
#include <stdlib.h>

#define MASS_INIT int A[] = {1, 3, 4, 2}, LEN = 4
//#define MASS_INIT int A[] = {8, 5, 11, 12, 2, 13, 1, 10, 9, 4, 7, 15, 6, 3, 16, 14}, LEN = 16


void sort(int A[], int low, int high);
void merge(int A[], int p, int q, int r);
void print_A(int l, int A[]);


int main()
{
	MASS_INIT;

	print_A(LEN, A);

	sort(A, 0, LEN-1);

	print_A(LEN, A);
	return 0;
}


void sort(int A[], int low, int high)
{
	int mid;

	if(low < high) {
		mid = (low + high) / 2;
		sort(A, low, mid);
		sort(A, mid + 1, high);
		merge(A, low, mid, high);
	} else {
		return;
	}
}


void merge(int A[], int low, int mid, int high)
{
	int i, j, k;

	int n1 = mid - low + 1;
	int n2 = high - mid;

	int L[n1], R[n2];

	for(i=0; i<n1; i++) {
		L[i] = A[low + i];
	}

	for(j=0; j<n2; j++) {
		R[j] = A[mid + j + 1];
	}

	i = 0;
	j = 0;

	for(k=low; k<=high; k++) {
		if (L[i] <= R[j] && i < n1) {
			A[k] = L[i];
			i++;
		}
		else if (j < n2) {
			A[k] = R[j];
			j++;
		}
		else {
			break;
		}
	}

	for(; i<n1; i++, k++)
		A[k] = L[i];

	for(;j<n2; j++, k++)
		A[k] = R[j];
}

void print_A(int l, int A[])
{
	int i;
	for (i=0;i<l;i++)
		printf("%d ", A[i]);
	printf("\n");
}

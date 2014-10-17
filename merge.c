#include <stdio.h>
#define N 10

int array[N], temp[N];

void merge(int L, int R)
{
	int M = (L+R)/2;
	int i = L, j = M, k = L;
	while (i < M && j < R) {
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < M)
		temp[k++] = array[i++];
	while (j < R)
		temp[k++] = array[j++];

	for (i = L; i < R; i++)
		array[i] = temp[i];
}

void mergeSort(int L, int R)
{
	if (R - L > 1) {
		int M = (L+R)/2;
		mergeSort(L, M);
		mergeSort(M, R);
		merge(L, R);
	}
}

int main()
{
	int i;
	for (i = 0; i < N; i++)
		scanf("%d", &array[i]);

	mergeSort(0, N);

	for (i = 0; i < N; i++)
		printf("%d ", array[i]);
}

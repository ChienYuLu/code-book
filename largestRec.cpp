#include <cstdio>

int A[10] = {2,1,3,3,4,2,1}, B[10];
int S[10], sp = 0;

int main()
{

	S[sp++] = -1;
	B[0] = 0;
	for (int i = 1; i < 7; i++) {
		if (A[i] > A[i-1]) {
			B[i] = i-1;
			S[sp++] = i-1;
		} else {
			while (sp != 0) {
				int top = S[sp-1];
				if (top == -1) {
					B[i] = 0;
					break;
				}
				if (A[i] > A[top]) {
					B[i] = top;
					break;
				}
				sp--;
			}
		}
	}
	for (int i = 0; i < 7; i++)
		printf("%d ", B[i]);
	printf("\n");
	return 0;
}

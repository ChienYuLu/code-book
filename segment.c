#include <stdio.h>
#define N 10

int array[N], tree[N*4];
int lazy[N*4];

void build(int L, int R, int t)
{
	if (R - L == 1) {
		tree[t] = array[L];
	} else {
		int M = (L+R) / 2;
		build(L, M, t*2);
		build(M, R, t*2+1);
		tree[t] = tree[t*2] + tree[t*2+1];
	}
}

void down(int L, int R, int M, int t)
{
	lazy[t*2] += lazy[t];
	lazy[t*2+1] += lazy[t];
	
	tree[t*2] += (M-L)*lazy[t];
	tree[t*2+1] += (R-M)*lazy[t];
	
	lazy[t] = 0;
}

int query(int L, int R, int x, int y, int t)
{
	if (y <= L || R <= x)
		return;
	if (L <= x && y <= R) {
		return tree[t];
	} else {
		int M = (L+R) / 2;
		if (lazy[t] != 0)
			down(L, R, M, t);
		int a = query(L, M, x, y, t*2);
		int b = query(M, R, x, y, t*2+1);
		
		return a + b;
	}
}

void update(int L, int R, int x, int y, int value, int t)
{
	if (y <= L || R <= x)
		return;
	if (L <= x && y <= R) {
		lazy[t] += value;
		tree[t] += (R-L)*value;
	} else {
		int M = (L+R) / 2;
		if (lazy[t] != 0)
			down(L, R, M, t);
		update(L, M, x, y, value, t*2);
		update(M, R, x, y, value, t*2+1);
	}
}

int main()
{
	int n, i;
	n = 10;
	for (i = 0; i < n; i++)
		array[i] = i+1;
		
	build(0, n, 1);
	
	update(0, n, 4, 9, 5, 1);
	printf("%d\n", query(0, n, 4, 9, 1));
	printf("%d\n", query(0, n, 1, 6, 1));
	
	update(0, n, 2, 6, 5, 1);
	printf("%d\n", query(0, n, 4, 9, 1));
	printf("%d\n", query(0, n, 7, 9, 1));

	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 5000000
using namespace std;

struct node {
	long long data;
	int left, right;
} tree[N];
int sz = 0;
int ver[N], vn = 0;

int new_node()
{
	int ret = sz;
	sz++;
	return ret;
}

void new_ver()
{
	int nn = new_node();
	ver[vn] = nn;
	tree[nn].data = tree[ver[vn-1]].data;
	tree[nn].left = tree[ver[vn-1]].left;
	tree[nn].right = tree[ver[vn-1]].right;
	vn++;
}

void init()
{
	sz = 0;
	vn = 0;
	tree[0].data = 0;
	tree[0].left = 0;
	tree[0].right = 0;
	sz++;
	ver[0] = 0;
	vn++;
}

void update(int L, int R, int x, long long y, int index)
{
	if (R-L == 1) {
		tree[index].data = y;
		return;
	}
	int nn = new_node();
	int M = (L+R)/2;
	if (x < M) {
		int l = tree[index].left;
		tree[nn].data = tree[l].data;
		tree[nn].left = tree[l].left;
		tree[nn].right = tree[l].right;
		tree[index].left = nn;
		update(L, M, x, y, nn);
	} else {
		int r = tree[index].right;
		tree[nn].data = tree[r].data;
		tree[nn].left = tree[r].left;
		tree[nn].right = tree[r].right;
		tree[index].right = nn;
		update(M, R, x, y, nn);
	}
	long long a = tree[tree[index].left].data;
	long long b = tree[tree[index].right].data;
	tree[index].data = a + b;
}

long long query(int L, int R, int x, int y, int index)
{
	if (x <= L && R <= y) return tree[index].data;
	if (R <= x) return 0L;
	if (y <= L) return 0L;
	long long a = query(L, (L+R)/2, x, y, tree[index].left);
	long long b = query((L+R)/2, R, x, y, tree[index].right);
	return a+b;
}

int main()
{
	int n, t;
	while (EOF != scanf("%d %d", &n, &t)) {
		init();
		while (t--) {
			new_ver();

			int cmd, x;
			scanf("%d", &cmd);
		if (cmd == 0) {
				scanf("%d", &x);
				tree[ver[vn-1]].data = tree[ver[vn-2-x]].data;
				tree[ver[vn-1]].left = tree[ver[vn-2-x]].left;
				tree[ver[vn-1]].right = tree[ver[vn-2-x]].right;
			} else if (cmd == 1) {
				long long y;
				scanf("%d %lld", &x, &y);
				x--;
				update(0, n, x, y, ver[vn-1]);
			} else {
				int y;
				scanf("%d %d", &x, &y);
				x--;
				printf("%lld\n", query(0, n, x, y, ver[vn-1]));
			}
		}
	}
	return 0;
}

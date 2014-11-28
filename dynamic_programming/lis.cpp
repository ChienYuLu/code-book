#include <cstdio>
#include <algorithm>
using namespace std;

int A[] = {1,6,2,3,7,5};
int d[6], g[10], b[10];
const int INF = 10000;

int main()
{
	int n = 6;
	for (int i = 1; i <= n; i++) g[i] = INF;
	for (int i = 0; i < n; i++) {
		int k = lower_bound(g+1, g+n+1, A[i]) - g;
		d[i] = k;
		g[k] = A[i];
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", d[i], b[i]);
}

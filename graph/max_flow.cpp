#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

long long adj[210][210];
int pre[210];
long long vst[210];
int n, m;

bool find_path(long long x)
{
	queue<int> q;
	q.push(1);
	bool ok = false;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == m) {
			ok = true;
			break;
		}
		for (int i = 0; i < 210; i++) {
			if (adj[cur][i] && vst[i] < x) {
				vst[i] = x;
				q.push(i);
				pre[i] = cur;
			}
		}
	}
	return ok;
}

long long find_min()
{
	int cur = pre[m];
	long long ret = adj[pre[m]][m];
	while (cur != 1) {
		ret = min(ret, adj[pre[cur]][cur]);
		cur = pre[cur];
	}
	return ret;
}

void flow(long long x)
{
	int cur = m;
	while (cur != 1) {
		adj[pre[cur]][cur] -= x;
		adj[cur][pre[cur]] += x;
		cur = pre[cur];
	}
}

int main()
{
	while (cin >> n >> m) {
		memset(adj, 0, sizeof(adj));
		memset(vst, 0, sizeof(vst));
		for (int i = 0; i < n; i++) {
			int a, b;
		       	long long c;
			cin >> a >> b >> c;
			adj[a][b] += c;
		}
		long long ans = 0;
		long long t = 1;
		while (find_path(t++)) {
			long long x = find_min();
			flow(x);
			ans += x;
		}
		cout << ans << endl;
	}
	return 0;
}


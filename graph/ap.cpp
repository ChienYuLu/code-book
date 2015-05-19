#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define N 110
using namespace std;

vector<int> adj[N];
int clk[N], low[N];
int ans;
int t;

// dfs(1, -1)

void dfs(int cur, int parent)
{
	int child = 0;
	bool flag = false;

	low[cur] = clk[cur] = t;
	t++;
	
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		if (!clk[next]) {
			child++;
			dfs(next, cur);
			low[cur] = min(low[cur], low[next]);

			if (low[next] >= clk[cur])
				flag = true;
		} else if (next != parent) {
			low[cur] = min(low[cur], clk[next]);
		}
	}

	if (parent == -1 && child >= 2)
		ans++;
	else if (parent != -1 && flag)
		ans++;
}

void init(int n)
{
	t = 1;
	ans = 0;
	memset(clk, 0, sizeof(clk));
	memset(low, 0, sizeof(low));
	for (int i = 0; i <= n; i++)
		adj[i].clear();
}

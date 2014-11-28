#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define N 10
using namespace std;

vector <int> adj[N]; //adj list
int degree[N]; //in degree
bool vst[N];

int main()
{
	int a, b, n;
	cin >> n;
	
	memset(degree, 0, sizeof(degree));
	memset(vst, false, sizeof(vst));
	while (cin >> a >> b) {
		adj[a].push_back(b);
		degree[b]++;
	} //build graph
	
	queue <int> q;
	for (int i = 0; i < n; i++)
		if (degree[i] == 0)
			q.push(i); //push degree 0 in queue
			
	for (int i = 0; i < n; i++) {
		int s = q.front(); q.pop();
		vst[s] = true;
	
		cout << s << ' ';
	
		for (int j = 0; j < v[s].size(); j++)//vector s can reach
			if (!vst[v[s][j]]) {
				degree[v[s][j]]--;
				if (degree[v[s][j]] == 0)
					q.push(v[s][j]);
			}
	}
	cout << endl;
	
	return 0;
}
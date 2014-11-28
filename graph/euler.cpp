#include <iostream>
#include <deque>
#include <cstring>
#define N 6
using namespace std;

int adj[N][N];
int degree[N];
deque< pair<int,int> > edge;

bool evenDegree()
{
	memset(degree, 0, sizeof(degree));

	for (int x = 0; x < N; x++)
		for (int y = x; y < N; y++) {
			degree[x] += adj[x][y];
			degree[y] += adj[x][y];
		}

	for (int x = 0; x < N; x++)
		if (degree[x]%2)
			return false;
	return true;
}

void findEulerCircuit(int x)
{
	for (int y = 0; y < N; y++)
		if (adj[x][y] > 0) {
			adj[x][y]--;
			if (x != y) adj[y][x]--;

			findEulerCircuit(y);
			edge.push_front( make_pair(x,y) );
		}
}

int main()
{
	int a, b;
	while (cin >> a >> b) {
		adj[a][b]++;
		if (a != b)
			adj[b][a]++;
	}
	findEulerCircuit(0);

	deque< pair<int,int> > :: iterator it;
	for (it = edge.begin(); it != edge.end(); it++)
		cout << it->first << ' ' << it->second << endl;

	return 0;
}

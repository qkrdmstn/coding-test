#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MXN = 32'005;

int n, m;
vector<int> adj[MXN];
int indeg[MXN];

void func()
{
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (indeg[i] == 0) {
				indeg[i]--;
				cout << i << ' ';
				for (auto nxt : adj[i])
					indeg[nxt]--;
				break;
			}
		}
	}

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indeg[v]++;
	}
	func();
	
	return 0;
}
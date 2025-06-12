#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int MXN = 1005;

vector<tuple<int, int, int>> edge;
int p[MXN];
int worstCost = 0;
int bestCost = 0;

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v) return false;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v])p[u]--;
	p[v] = u;
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, a, b });
	}

	fill(p, p + n + 1, -1);
	int cnt = 0;
	sort(edge.begin(), edge.end(), greater<tuple<int, int, int>>());
	for (auto e : edge) {
		int cost, a, b;
		tie(cost, a, b) = e;
		//이미 연결된 정점이면 continue
		if (!uni(a, b)) continue;
		//오르막 count
		if(cost == 0)
			bestCost++;
		cnt++;
		if (cnt == n) break;
	}

	cnt = 0;
	fill(p, p + n + 1, -1);
	sort(edge.begin(), edge.end());
	for (auto e : edge) {
		int cost, a, b;
		tie(cost, a, b) = e;
		//이미 연결된 정점이면 continue
		if (!uni(a, b)) continue;
		//오르막 count
		if (cost == 0)
			worstCost++;
		cnt++;
		if (cnt == n) break;
	}
	cout << worstCost * worstCost - bestCost * bestCost;
	return 0;
}
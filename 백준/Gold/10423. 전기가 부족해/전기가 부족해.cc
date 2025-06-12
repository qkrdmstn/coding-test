#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;

#define X first
#define Y second

const int MXN = 1005;

vector<tuple<int, int, int>> edge;
vector<pair<int, int>> pos;
vector<int> p(MXN, -1);
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

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int city;
		cin >> city;
		//가상 노드 0번과 발전소가 있는 도시들을 연결
		uni(city, 0);
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({ w,u,v });
	}

	sort(edge.begin(), edge.end());

	n++;
	int cnt = 0;
	int ans = 0;
	for (auto e: edge) {
		int c, a, b;
		tie(c, a, b) = e;
		if (!uni(a, b)) continue;
		cnt++;
		ans += c;
		if (cnt == n - 1) break;
	}

	cout << ans;
	return 0;
}
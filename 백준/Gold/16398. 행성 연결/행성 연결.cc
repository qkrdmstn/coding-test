#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int MXN = 1005;

vector<tuple<int, int, int>> edge;
vector<int> p(MXN, -1);

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

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c;
			cin >> c;
			if (i >= j) continue;
			edge.push_back({ c, i, j });
		}
	}

	sort(edge.begin(), edge.end());

	int cnt = 0;
	long long ans = 0;
	for (auto e : edge) {
		int cost, a, b;
		tie(cost, a, b) = e;
		//이미 연결된 정점이면 continue
		if (!uni(a, b)) continue;
		cnt++;
		ans += cost;
		if (cnt == n - 1) break;
	}
	cout << ans;
	return 0;
}
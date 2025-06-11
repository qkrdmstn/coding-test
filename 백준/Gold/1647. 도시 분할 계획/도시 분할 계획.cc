#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int MXN = 100005;

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

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, a, b });
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
		if (cnt == n - 2) break;
	}
	if (n == 2) cout << 0;
	else cout << ans;
	return 0;

	//마을을 2개로 분리한다는 것은
	//최소 신장 트리로 모든 집을 연결하고, 이중에서 가장 비용이 큰 간선 하나를
	//끊어 최소 비용으로 각 마을을 만드는 그래프를 구성할 수 있다.
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int MXN = 10005;
vector<int> p(MXN, -1);
vector<tuple<int, int, int>> e;
int V, E;
int ans;

int find(int x)
{
	if (p[x] < 0)
		return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	//v의 랭크가 더 높으면 swap
	if (p[v] < p[u])
		swap(u, v);
	//두 그룹의 랭크가 같으면 합쳐지는 그룹의 랭크를 증가
	if (p[u] == p[v])
		p[u]--;
	//v그룹을 u그룹으로 병합
	p[v] = u;
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({ c,a,b });
	}

	//간선을 비용 오름차순으로 정렬
	sort(e.begin(), e.end());

	for (int i = 0; i < E; i++) {
		int cost, a, b;
		tie(cost, a, b) = e[i];
		//같은 그룹이라면 continue;
		if (find(a) == find(b)) continue;
		//다른 그룹이면 병합 후, 비용 합산
		uni(a, b);
		ans += cost;
	}
	cout << ans;
	return 0;
}
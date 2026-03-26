#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f;
int main(void)
{

	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edge;
	vector<ll> dist(n+1, INF);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({a, b, c});
	}

	dist[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (auto &e : edge)
		{
			int a, b, c;
			tie(a, b, c) = e;

			if(dist[a] != INF && dist[a] + c < dist[b])
				dist[b] = dist[a] + c;
		}
	}

	for (auto& e : edge)
	{
		int a, b, c;
		tie(a, b, c) = e;

		if (dist[a] != INF && dist[a] + c < dist[b])
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if(dist[i] == INF) cout << -1 << "\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}
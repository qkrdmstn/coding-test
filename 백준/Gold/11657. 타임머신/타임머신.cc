#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> edge;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({a, b, c});
	}

	vector<ll> dist(n+1, INF);
	dist[1] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int from, to, cost;
			tie(from, to, cost) = edge[j];

			if(dist[from] != INF && dist[from] + cost < dist[to])
				dist[to] = dist[from] + cost;
		}
	}


	for (int j = 0; j < m; j++)
	{
		int from, to, cost;
		tie(from, to, cost) = edge[j];

		if (dist[from] != INF && dist[from] + cost < dist[to])
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
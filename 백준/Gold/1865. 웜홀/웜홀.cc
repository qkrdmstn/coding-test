#include <iostream>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, w;
		cin >> n >> m >> w;
		vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
		for (int i = 1; i <= n; i++)
			dist[i][i] = 0;
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			dist[a][b] = min(dist[a][b], c);
			dist[b][a] = min(dist[b][a], c);
		}
		for (int i = 0; i < w; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			dist[a][b] = min(dist[a][b], -c);
		}


		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (dist[i][k] + dist[k][j] < dist[i][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
		bool ans = false;
		for (int i = 1; i <= n; i++)
		{
			if(dist[i][i] < 0)
				ans = true;
		}
		if(ans) cout <<"YES\n";
		else cout << "NO\n";
	}
	return 0;
}
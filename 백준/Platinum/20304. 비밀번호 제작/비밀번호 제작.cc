#include <iostream>
#include <queue>
using namespace std;

int n, m, depth;
int maxBitSize = 0;
int p[100001];
int dist[1000001];
queue<int> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		dist[i] = -1;
	for (int i = 0; i < m; i++) {
		cin >> p[i];
		q.push(p[i]);
		dist[p[i]] = 0;
	}


	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cur = q.front();
			q.pop();

			for (int shift = 0; shift < 31; shift++) {
				int next = cur ^ (1 << shift);

				if (next > n)
					continue;
				if (dist[next] != -1)
					continue;

				q.push(next);
				dist[next] = dist[cur] + 1;
			}
		}

		depth++;
	}
	cout << depth - 1;
	return 0;
}
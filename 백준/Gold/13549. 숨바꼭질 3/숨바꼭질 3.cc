#include<iostream>
#include<queue>
using namespace std;

int n, k;
queue<int> q;
int map[100001];
int dist[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < 100001; i++)
	{
		dist[i] = 100001;
	}

	q.push(n);
	dist[n] = 0;

	while (dist[k] == 100001) {
		int cur = q.front();
		q.pop();

		for (int next : {2 * cur, cur - 1, cur + 1}) {

			if (next < 0 || next > 100000)
				continue;
			int nextDist = (next == 2 * cur) ? dist[cur] : dist[cur] + 1;

			if (nextDist < dist[next] ) {
				q.push(next);
				dist[next] = nextDist;
				continue;
			}
			if (dist[next] != 100001)
				continue;

			q.push(next);
			dist[next] = nextDist;
		}
	}
	cout << dist[k];

	return 0;
}
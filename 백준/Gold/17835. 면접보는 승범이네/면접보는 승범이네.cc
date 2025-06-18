#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
typedef long long ll;

#define X first
#define Y second

const ll INF = 0x7f7f7f7f7f7f;

int n, m, k;
vector<pair<int, int>> adj[100'005];
priority_queue< pair<ll, int>,
	vector<pair<ll, int>>,
	greater<pair<ll, int>> > pq;
ll cost[100'005];

void daijkstra()
{
	while (!pq.empty()) {
		ll c;
		int x;
		tie(c, x) = pq.top(); pq.pop();

		if (cost[x] != c) continue;
		for (auto nxt: adj[x]) {
			if (cost[nxt.Y] <= cost[x] + nxt.X) continue;
			cost[nxt.Y] = cost[x] + nxt.X;
			pq.push({ cost[nxt.Y], nxt.Y});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[v].push_back({ c,u });
	}

	fill(cost, cost + n + 1, INF);
	while (k--) {
		int city;
		cin >> city;
		cost[city] = 0;
		pq.push({ cost[city], city });
	}

	daijkstra();

	int maxIdx = 1;
	for (int i = 2; i <= n; i++) {
		if (cost[maxIdx] < cost[i])
			maxIdx = i;
	}
	cout << maxIdx << '\n' << cost[maxIdx];
	return 0;

	/*
	각 도시에서 다익스트라를 수행할 시, O(VElgE)가 되어 시간 초과가 발생
	따라서, 면접장에서 도시로 가는 다익스트라를 수행
	이때, 단방향 길이기 때문에 길을 거꾸로 입력하고,
	면접장이 여러개이기 때문에 하나로 취급하여 우선순위 큐에 모두 삽입한다.
	이러면 한 번의 다익스트라 수행으로 문제를 풀 수 있다.

	+) N은 10^5, C 10^5 이므로 N*C = 최대 10^10 범위 -> int 범위 초과
	*/
}
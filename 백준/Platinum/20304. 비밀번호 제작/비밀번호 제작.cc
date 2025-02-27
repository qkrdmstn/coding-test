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

			for (int shift = 0; shift < 20; shift++) {
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

	/* 크게 2가지를 생각해야 한다.
	1. 안전거리 계산: 이는 단순히 1을 shift 시킨 후, XOR 연산을 진행하면 1의 자리수만 반전된 수가 도출되기 때문에,
	현재 숫자에서 안전거리가 1인 다음 숫자를 도출할 수 있다. 이러한 연산을 Bit-Mask라고도 한다.
	
	2. 입력 시도된 비밀번호들에서 동시에 1.을 활용한 BFS를 수행하면 각 시도된 비밀번호로부터 최단 안전거리부터 방문하게 되고
	방문된 숫자의 최소 안전 거리가 계산된다. 

	예를 들어, 3으로부터 안전거리 1인 2가 도출되었으면, 새로운 비밀번호를 2로 설정했을 때 3에 의해 가장 빨리 방문되었으므로, 
	최소 안전거리가 1이 되어 안전도가 1이 되는 것이다.
	
	이를 활용해 가장 높은 안전도를 계산하고 싶다면, BFS의 Depth가 곧 해당 값이 된다.
	*/
	return 0;
}
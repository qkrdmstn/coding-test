#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 1'005;

int t, n, k, w;
vector<int> adj[MXN];
int indeg[MXN];
int delay[MXN]; //각 건물 건설에 걸리는 시간
int endTime[MXN]; //각 건물의 건설이 끝나는 시간

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> delay[i];
			//초기화
			endTime[i] = 0;
			indeg[i] = 0;
			adj[i].clear();
		}

		for (int i = 1; i <= k; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			indeg[y]++;
		}

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (indeg[i] == 0) {
				q.push(i);
				endTime[i] = delay[i];
			}
		}

		cin >> w;
		//위상 정렬 순회
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == w) {
				cout << endTime[cur] << '\n';
				break;
			}
			for (int nxt : adj[cur]) {
				//다음 작업의 끝나는 시간 = 
				//선행 작업 중 가장 늦게 끝난 작업의 시간 + 현재 작업의 소요 시간
				endTime[nxt] = max(endTime[nxt], endTime[cur] + delay[nxt]);
				indeg[nxt]--;
				if (indeg[nxt] == 0)
					q.push(nxt);
			}
		}
	}

	return 0;
}
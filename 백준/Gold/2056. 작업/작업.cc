#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 32'005;

int n;
vector<int> adj[MXN];
int indeg[MXN];
int dur[MXN]; //각 작업에 걸리는 시간
int t[MXN]; //각 작업이 끝나는 시간
queue<int> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> dur[i] >> cnt;

		//indegree == 0인 작업
		if (cnt == 0) {
			q.push(i);
			t[i] = dur[i];
		}

		while (cnt--) {
			int u;
			cin >> u;
			adj[u].push_back(i);
			indeg[i]++;
		}
	}

	//위상 정렬 순회
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur]) {
			//다음 작업의 끝나는 시간 = 
			//선행 작업 중 가장 늦게 끝난 작업의 시간 + 현재 작업의 소요 시간
			t[nxt] = max(t[nxt], t[cur] + dur[nxt]);
			indeg[nxt]--;
			if (indeg[nxt] == 0)
				q.push(nxt);
		}
	}
	
	//작업 중 가장 늦게 끝난 시간 찾기
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, t[i]);
	cout << ans;
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 1'000'005;

int n, root;
vector<int> adj[MXN], tree[MXN], state[MXN];

//자식 정보만을 가지도록 트리 구성
void mktree(int cur, int prev)
{
	for (int nxt : adj[cur]) {
		if (nxt == prev) continue;
		tree[cur].push_back(nxt);
		mktree(nxt, cur);
	}
}

//현재 노드가 earlyadptor = true/false 일 때 해당 노드의 서브 트리의 earlyadaptor 노드의 개수
int dp(int cur, bool isEarlyAdaptor)
{
	if (state[cur][isEarlyAdaptor] != -1)
		return state[cur][isEarlyAdaptor];

	int val = 0;
	//현재 노드가 earlyadaptor라면,
	if (isEarlyAdaptor) {
		//자식 노드는 true/false 관계 없으므로 더 적은 걸 선택
		for (int nxt : tree[cur])
			val += min(dp(nxt, false), dp(nxt, true));
	}
	//현재 노드가 false라면,
	else {
		//자식 노드는 무조건 true여야 함.
		for (int nxt : tree[cur])
			val += dp(nxt, true);
	}
	//현재 노드에 대한 dp 테이블 값 설정
	state[cur][isEarlyAdaptor] = val + isEarlyAdaptor;
	return state[cur][isEarlyAdaptor];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		state[i].push_back(-1);
		state[i].push_back(-1);
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	mktree(1, -1);

	//첫 노드가 true/false인 경우 중 더 적은 걸 출력
	cout << min(dp(1, false), dp(1, true));
	return 0;
}
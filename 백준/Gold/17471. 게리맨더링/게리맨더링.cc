#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<int> people(15, 0);
vector<int> adj[12];

//백트래킹에 의해 나눠진 구역이 실제로 유효한지, 유효하면 두 구역의 인구 차이를 반환
int BFS(int cnt1, int cnt2, vector<int>& res, int n)
{
	//한 구역엔 반드시 노드가 하나 이상 포함돼야 함.
	if (cnt1 == 0 || cnt2 == 0)
		return INF;

	int start1, start2;
	for (int i = 0; i < n; i++)
	{
		if (res[i] == 0)
			start1 = i;
		else if (res[i] == 1)
			start2 = i;
	}

	int peopleCnt1 = 0, peopleCnt2 = 0;
	queue<int> q;
	vector<bool> vis(n, false);

	q.push(start1);
	q.push(start2);
	vis[start1] = true;
	vis[start2] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if(res[cur] == 0)
			peopleCnt1 += people[cur];
		else
			peopleCnt2 += people[cur];

		for (auto& nxt : adj[cur])
		{
			if(vis[nxt]) continue;
			if(res[nxt] != res[cur]) continue; //같은 구역만 지나가기
			q.push(nxt);
			vis[nxt] = true;
		}
	}

	//연결되지 않은 구역이 존재
	for(int i=0; i<n; i++)
	{
		if(!vis[i]) return INF;
	}

	return abs(peopleCnt1 - peopleCnt2);
}

//모든 구역을 A구역, B구역으로 각각 설정해보는 모든 경우의 수를 수행
void DFS(int cnt1, int cnt2, int cur, int n, vector<int>& res, int& ans)
{
	if (cnt1 + cnt2 == n)
	{
		ans = min(ans, BFS(cnt1, cnt2, res, n));
		return;
	}

	res.push_back(0);
	DFS(cnt1 + 1, cnt2, cur + 1, n, res, ans);
	res.pop_back();

	res.push_back(1);
	DFS(cnt1, cnt2 + 1, cur + 1, n, res, ans);
	res.pop_back();
}

int main(void)
{
	int n;
	cin >> n;

	for(int i=0; i<n; i++)
		cin >> people[i];

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int to;
			cin >> to;
			adj[i].push_back(to - 1);
		}
	}

	vector<int> res;
	int ans = INF;
	DFS(0, 0, 0, n, res, ans);
	if(ans == INF) cout << -1;
	else cout << ans;
	return 0;
}
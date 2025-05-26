#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MXN = 1'005;

int n, m;
string name[MXN];
unordered_map<string, int> id;

vector<int> adj[MXN];
vector<int> ch[MXN];
int indegree[MXN];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> name[i];
	sort(name + 1, name + n + 1);
	for (int i = 1; i <= n; i++)
		id[name[i]] = i;

	cin >> m;
	for (int i = 0; i < m; i++) {
		string u, v;
		cin >> u >> v;
		adj[id[v]].push_back(id[u]);
		indegree[id[u]]++;
	}

	//각 정점의 indegree count
	vector<int> root;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			root.push_back(i);
	}
	
	cout << root.size() << '\n';
	for (int ac : root)
		cout << name[ac] << ' ';
	cout << '\n';

	//바로 아래 자식들(indegree가 1 차이)만 ch 배열에 저장
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
		for (int c : adj[i]) {
			if (indegree[c] - indegree[i] == 1)
				ch[i].push_back(c);
		}
	}

	// 해당하는 사람과 자식의 수, 그리고 자식들의 이름을 출력
	for (int i = 1; i <= n; i++) {
		int sz = ch[i].size();
		cout << name[i] << ' ' << sz << ' ';
		for (int c : ch[i])
			cout << name[c] << ' ';
		cout << '\n';
	}

	/*
	indegree는 트리에서 level을 의미
	-> a노드의 조상을 모두 말해주기 때문에 그래프로 간선 연결 시,
	indegree = 조상 노드의 개수이기 때문
	*/
	return 0;
}
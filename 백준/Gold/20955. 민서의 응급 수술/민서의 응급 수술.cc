#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int find(int x, vector<int>& p)
{
	if (p[x] == -1) return x;
	return p[x] = find(p[x], p);
}

bool uni(int u, int v, vector<int>& p)
{
	u = find(u, p), v = find(v, p);
	if(u == v) return false;
	p[u] = v;
	return true;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	vector<tuple<int, int>> edge(m);
	vector<int> p(n+1, -1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[i] = {a, b};
	}

	int cut = 0, connect = 0;
	// 1. 유니온파인드로 사이클이 생기는 시냅스를 끊는다.
	for (auto& e : edge)
	{
		int a, b;
		tie(a, b) = e;

		
		if (!uni(a, b, p))
			cut++;
	}
	// 2. 트리를 만드는 데에 필요한 간선의 수는 n-1개이므로,
	// n-1 - 남은 간선을 통해 연결할 간선의 수를 정한다.
 	connect = (n-1) - (m-cut);
	cout << cut + connect;
	return 0;
}
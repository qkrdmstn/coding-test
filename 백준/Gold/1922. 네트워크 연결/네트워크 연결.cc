#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int find(int x, vector<int>& p)
{
	if(p[x] == -1)
		return x;
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
	
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({c, a, b});
	}

	sort(edges.begin(), edges.end());
	
	vector<int> p(n+1, -1);
	int edgeCnt = 0;
	int totalCost = 0;
	int i = 0;
	while(edgeCnt < n-1)
	{
		int a, b, c;
		tie(c, a, b) = edges[i];
		if (uni(a, b, p))
		{
			totalCost += c;
			edgeCnt++;
		}
		i++;
	}
	cout << totalCost;
}
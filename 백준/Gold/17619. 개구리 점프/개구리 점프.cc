#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

vector<int> p(100005,-1);
int find(int x)
{
	if(p[x] == -1) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u), v = find(v);
	if(u==v) return false;
	p[u] = v;
	return true;
}

int main(void)
{
	int n, q;
	cin >> n >> q;

	vector<tuple<int, int, int>> bridge(n+1);
	for (int i = 1; i <= n; i++)
	{
		int x1, x2, y;
		cin >>x1 >>x2 >> y;
		bridge[i] = {x1,x2,i};
	}
	sort(bridge.begin(), bridge.end());

	for (int i = 1; i <= n; i++)
	{
		int xi1, xi2, idxi;
		tie(xi1, xi2, idxi) = bridge[i];
		for (int j = i + 1; j <= n; j++)
		{
			int xj1, xj2, idxj;
			tie(xj1, xj2, idxj) = bridge[j];
			if(xj1 <= xi2) uni(idxi, idxj);
			else break;
		}
	}

	while (q--)
	{
		int a, b;
		cin >> a >> b;
		if(find(a) == find(b)) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
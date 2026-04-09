#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

vector<int> p(100005,-1);
int find(int x)
{
	if(p[x] <= -1) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u), v = find(v);
	if(u==v) return false;

	if(p[u] > p[v])
		swap(u, v);
	if(p[u] == p[v])
		p[u]--;
	p[v] = u;
	return true;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, q;
	cin >> n >> q;

	vector<tuple<int, int, int>> bridge(n+1);
	for (int i = 1; i <= n; i++)
	{
		int x1, x2, y;
		cin >>x1 >>x2 >> y;
		bridge[i] = {x1,x2,i};
	}
	sort(bridge.begin() + 1, bridge.end());

	int cx1, cx2, cidx;
	tie(cx1, cx2, cidx) = bridge[1];
	for (int i = 2; i <= n; i++)
	{
		int nx1, nx2, nidx;
		tie(nx1, nx2, nidx) = bridge[i];

		if (nx1 <= cx2)
		{
			uni(cidx, nidx);
			cx2 = max(cx2, nx2);
		}
		else
		{
			cidx = nidx;
			cx1 = nx1;
			cx2 = nx2;
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
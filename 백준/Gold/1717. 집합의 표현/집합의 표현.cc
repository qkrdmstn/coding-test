#include <iostream>
#include <vector>
using namespace std;

const int MXN = 1'000'005;

int n, m;
vector<int> p(MXN, -1);

int find(int x)
{
	if (p[x] < 0)
		return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (p[u] > p[v])
		swap(u, v);
	if (p[u] == p[v])
		p[u]--;
	p[v] = u;
	return true;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int c, a, b;
		cin >> c >> a >> b;
		if (c == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
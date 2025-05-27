#include <iostream>
#include <vector>
using namespace std;

const int MXN = 1'000'005;

int t, n, k, m;
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

	cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Scenario " << i << ":\n";
		cin >> n >> k;
		fill(p.begin(), p.end() + 1, -1);
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
				uni(a, b);
		}

		cin >> m;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			cout << (find(a) == find(b)) << '\n';
		}
		cout << '\n';
	}

	return 0;
}
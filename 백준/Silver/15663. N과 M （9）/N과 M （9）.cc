#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans[9], a[9];
bool vis[9];

void dfs(int len)
{
	if (len == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i] || tmp == a[i]) continue;
		vis[i] = true;
		ans[len] = a[i];
		tmp = a[i];
		dfs(len + 1);
		vis[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	dfs(0);
	return 0;
}

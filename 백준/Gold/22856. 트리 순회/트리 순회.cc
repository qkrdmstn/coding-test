#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, cnt, ed, ans;
int lc[100'005];
int rc[100'005];
int p[100'005];
bool vis[100'005];

void sinorder(int cur)
{
	vis[cur] = true;
	ans++;
	if (lc[cur] != -1 && !vis[lc[cur]]) sinorder(lc[cur]);
	else if (rc[cur] != -1 && !vis[rc[cur]]) sinorder(rc[cur]);
	else if (cur == ed) return;
	else if (p[cur] != -1) sinorder(p[cur]);
}

void inorder(int cur)
{
	if (lc[cur] != -1) inorder(lc[cur]);
	cnt++;
	if (cnt == n)
		ed = cur;
	if (rc[cur] != -1) inorder(rc[cur]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n ;
	fill(lc, lc + n + 1, -1);
	fill(rc, rc + n + 1, -1);
	fill(p, p + n + 1, -1);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		lc[a] = b;
		rc[a] = c;
		p[b] = a;
		p[c] = a;
	}

	inorder(1);
	sinorder(1);
	cout << ans - 1;
	return 0;
}
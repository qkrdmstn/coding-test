#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, delNode, root, ans;
vector<int> c[55];

void bfs()
{
	if (root == delNode) return;
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		bool isLeaf = true;
		for (int child : c[cur]) {
			if (child == delNode) continue;
			isLeaf = false;
			q.push(child);
		}
		if (isLeaf) ans++;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		if (p == -1) { root = i; continue; }
		c[p].push_back(i);
	}

	cin >> delNode;
	bfs();
	cout << ans;
	return 0;
}
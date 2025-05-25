#include <iostream>
#include <vector>
using namespace std;

int n, m, root;
int parent[10005];
int lc[10005];
int rc[10005];
int level[10005];
vector<int> row[10'005]; //각 레벨 별 {위치}
long long pos = 1;
int maxLevel = 1;

void inorder(int cur)
{
	int l = lc[cur];
	int r = rc[cur];
	if (l != -1) {
		level[l] = level[cur] + 1;
		maxLevel = max(maxLevel, level[l]);
		inorder(l);
	}

	row[level[cur]].push_back(pos++);
	
	if (r != -1) {
		level[r] = level[cur] + 1;
		maxLevel = max(maxLevel, level[r]);
		inorder(r);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p, l, r;
		cin >> p >> l >> r;
		lc[p] = l;
		rc[p] = r;

		if (l != -1) parent[l] = p;
		if (r != -1) parent[r] = p;
	}

	for (int i = 1; i <= n; i++) {
		if (parent[i] == 0) {
			root = i;
			break;
		}
	}

	level[root] = 1;
	inorder(root);

	long long maxWidth = 0;
	int ansLevel = 0;
	for (int i = 1; i <= maxLevel; i++) {
		int width = row[i][row[i].size() - 1] - row[i][0] + 1;
		if (maxWidth < width) {
			maxWidth = width;
			ansLevel = i;
		}
	}
	cout << ansLevel << ' ' << maxWidth;

	/*
	중위 순회를 통해 각 노드를 열 순서대로 순회 가능
	이때, 각 노드의 레벨도 함께 계산하면서 각 행(레벨)에 포함된 노드의 위치를 벡터에 저장
	최종적으로 각 레벨의 첫 번째 원소와 마지막 원소를 통해 넓이 계산 가능
	*/
	return 0;
}
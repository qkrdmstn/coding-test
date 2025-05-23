#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char lc[30];
char rc[30];

void preorder(int cur)
{
	cout << char(cur + 'A' - 1);
	if (lc[cur] != 0) preorder(lc[cur]);
	if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur)
{
	if (lc[cur] != 0) inorder(lc[cur]);
	cout << char(cur + 'A' - 1);
	if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur)
{
	if (lc[cur] != 0) postorder(lc[cur]);
	if (rc[cur] != 0) postorder(rc[cur]);
	cout << char(cur + 'A' - 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		char p, l, r;
		cin >> p >> l >> r;
		if (l != '.')lc[p - 'A' + 1] = l - 'A' + 1;
		if (r != '.')rc[p - 'A' + 1] = r - 'A' + 1;
	}

	preorder(1); cout << '\n';
	inorder(1); cout << '\n';
	postorder(1); cout << '\n';
	return 0;
}
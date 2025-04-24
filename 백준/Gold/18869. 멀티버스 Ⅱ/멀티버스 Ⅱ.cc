#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
int space[105][10005];

void compress(int a[])
{
	vector<int> v(a, a + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++)
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
}

bool IsBalanced(int a[], int b[])
{
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for(int j=0; j<n; j++)
			cin >> space[i][j];	
		compress(space[i]);
	}

	int ans = 0;
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			if(IsBalanced(space[i], space[j]))
				ans++;
		}
	}
	cout << ans;

	return 0;

	/*
	두 우주를 좌표 압축했을 때, 동일하면 균등한 우주.
	*/
}
#include <iostream>
using namespace std;

int n, ans = -1005;
int a[100005];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int curSum = 0;
	for (int i = 0; i < n; i++) {
		curSum += a[i];
		ans = max(ans, curSum);
		if (curSum < 0)
			curSum = 0;
	}
	cout << ans;
	return 0;
}
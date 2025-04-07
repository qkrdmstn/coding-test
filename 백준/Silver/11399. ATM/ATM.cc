#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);

	int ans = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		ans += t + p[i];
		t += p[i];
	}
	cout << ans;
	return 0;
}
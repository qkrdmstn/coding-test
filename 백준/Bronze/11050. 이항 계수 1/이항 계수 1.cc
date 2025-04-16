#include <iostream>
using namespace std;

int n, k;
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;
	int ans = 1;
	for (int i = 1; i <= n; i++) ans *= i;
	for (int i = 1; i <= k; i++) ans /= i;
	for (int i = 1; i <= n-k; i++) ans /= i;
	cout << ans;
	return 0;
}
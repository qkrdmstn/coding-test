#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;;
	cin >> n;
	
	for (int i = 5; i <= n; i *= 5) {
		ans += n / i;
	}
	cout << ans;
	return 0;
}
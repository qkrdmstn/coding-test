#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	
	int ans = 0;
	while (n != 0) {
		ans += n / 5;
		n /= 5;
	}
	cout << ans;
	return 0;
}
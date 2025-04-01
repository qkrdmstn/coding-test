#include <iostream>
using namespace std;

int t, n;
long long d[101];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	for (int i = 5; i <= 100; i++)
		d[i] = d[i - 2] + d[i - 3];

	while (t--) {
		cin >> n;
		cout << d[n] << '\n';
	}

	return 0;
}
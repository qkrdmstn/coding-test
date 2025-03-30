#include <iostream>
using namespace std;

int n;
int d[1005];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	d[1] = 1;
	d[2] = 2;

	cin >> n;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 2] + d[i - 1]) % 10007;

	cout << d[n];
	
	return 0;
}
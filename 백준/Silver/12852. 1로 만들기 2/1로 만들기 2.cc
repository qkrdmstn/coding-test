#include <iostream>
using namespace std;

int n;
int d[10000005];
int pre[10000005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n ;
	
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;

		if (i % 2 == 0 && d[i / 2] + 1 < d[i]) {
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2;
		}
		if (i % 3 == 0 && d[i / 3] + 1 < d[i]) {
			d[i] = d[i / 3] + 1;
			pre[i] = i / 3;
		}
	}

	cout << d[n] << '\n';
	int i = n;
	while (true) {
		cout << i << ' ';
		if (i == 1) break;
		i = pre[i];
	}
	return 0;
}
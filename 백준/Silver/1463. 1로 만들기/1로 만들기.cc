#include <iostream>
using namespace std;

int n;
int table[1000001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	table[1] = 0;
	for (int i = 2; i <= n; i++) {
		int m = table[i - 1] + 1;
		if (i % 2 == 0)
			m = min(table[i / 2] + 1, m);
		if (i % 3 == 0)
			m = min(table[i / 3] + 1, m);
		table[i] = m;
	}

	cout << table[n];
	return 0;
}
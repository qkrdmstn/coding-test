#include <iostream>
using namespace std;

int t,n;
int table[11] = {};
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;

	table[1] = 1;
	table[2] = 2;
	table[3] = 4;

	for (int i = 4; i < 11; i++)
		table[i] = table[i - 1] + table[i - 2] + table[i - 3];
	while (t--) {
		cin >> n;
		cout << table[n] << '\n';
	}

	return 0;
}
#include <iostream>
using namespace std;

int n, total;
int stair[301];
int table[301];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
		total += stair[i];
	}
	
	table[1] = stair[1];
	table[2] = stair[2];
	table[3] = stair[3];

	for (int i = 4; i <= n; i++)
		table[i] = min(table[i-2], table[i-3]) + stair[i];

	cout << total - min(table[n - 1], table[n - 2]);
	return 0;
}
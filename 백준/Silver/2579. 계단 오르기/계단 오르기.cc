#include <iostream>
using namespace std;

int n;
int stair[301];
int table[301][3];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}
	
	table[1][1] = stair[1];
	table[1][2] = 0;
	table[2][1] = stair[2];
	table[2][2] = stair[1] + stair[2];
	
	for (int i = 3; i <= n; i++) {
		table[i][1] = max(table[i - 2][1], table[i-2][2]) + stair[i];
		table[i][2] = table[i - 1][1] + stair[i];
	}
	cout << max(table[n][1], table[n][2]);
	return 0;
}
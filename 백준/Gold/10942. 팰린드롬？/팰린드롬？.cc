#include <iostream>
using namespace std;

int n, t;
int arr[2005];
int d[2005][2005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		d[i][i] = 1;
		if (arr[i - 1] == arr[i]) d[i - 1][i] = 1;
	}

	for (int diff = 2; diff < n; diff++) {
		for (int i = 0; i <= n - diff; i++) {
			int s = i; int e = i + diff;
			if (arr[s] == arr[e] && d[s + 1][e - 1]) d[s][e] = 1;
		}
	}

	cin >> t;
	while (t--) {
		int s, e;
		cin >> s >> e;
		cout << d[s][e] << '\n';
	}

	/*
	설명:
	d[s][e]: s번째 수부터 e번째 수가 팰린드롬 수인지 나타냄
	길이가 1인 수는 무조건 팰린드롬 => d[i][i] = 1;
	길이가 2인 수는 직전과 같으면 팰린드롬 => arr[i-1] == arr[i] : d[i-1][i] = 1;
	길이가 n인 수는 시작과 끝이 같고, 그 사이에 있는 수가 팰린드롬이면 팰린드롬
	-> arr[s] == arr[e] && d[s + 1][e - 1] : d[s][e] = 1;
	*/
	return 0;
}
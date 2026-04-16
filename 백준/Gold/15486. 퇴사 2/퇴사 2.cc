#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<pair<int, int>> info(n + 1); //{기간, 보상}
	for (int i = 1; i <= n; i++)
	{
		int p, r;
		cin >> p >> r;
		info[i] = { p, r };
	}

	vector<int> dp(n + 2, 0); // i번째 일부터 n일까지 벌 수 있는 최대 이익
	for (int i = n; i >= 1; i--)
	{
		int endDay = i + info[i].first - 1;
		if (endDay > n)
			dp[i] = dp[i + 1];
		else
		{
			int pi = info[i].second;
			dp[i] = max(dp[i + 1], pi + dp[endDay + 1]); //i번째 일을 건너뛰거나, 강의를 하고 + 끝난 다음 날 강의를 시작하거나
		}
	}
	cout << dp[1];
}
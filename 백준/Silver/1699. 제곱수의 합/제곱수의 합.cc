#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	//dp[i]: i를 제곱의 합으로 표현했을 때 최소항의 개수
	vector<int> dp(n + 1, 0x3f3f3f3f13);
	for (int i = 1; i * i <= n; i++)
		dp[i * i] = 1;

	for (int i = 2; i <= n; i++)
	{
		//dp[i] = dp[i - 제곱수] + 1(제곱수의 항 개수) 중 가장 작은 것
		for (int j = 1; j * j < i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}
	cout << dp[n];
	return 0;
}
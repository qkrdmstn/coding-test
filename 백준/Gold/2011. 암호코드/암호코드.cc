#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int PRIME = 1'000'000;

int main(void)
{
	string s;
	cin >> s;

	s = " " + s;
	int len = s.length();

	vector<int> dp(len + 1, 0);
	dp[0] = 1;
	for (int i = 1; i < len; i++)
	{
		if (s[i] != '0')
			dp[i] = (dp[i] + dp[i - 1]) % PRIME;
		int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (i >= 2)
		{
			if (10 <= num && num <= 26)
				dp[i] = (dp[i] + dp[i - 2]) % PRIME;
		}
	}
	cout << dp[len - 1];
	return 0;
}
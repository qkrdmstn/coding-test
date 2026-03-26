#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<pair<int, int>> line;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		line.push_back({a, b});
	}
	sort(line.begin(), line.end());

	vector<int> dp(n, 1);
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (line[j].second < line[i].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int ans = 0;
	for(int i=0; i<n; i++)
		ans = max(ans, dp[i]);
	cout << n - ans;
	return 0;
}
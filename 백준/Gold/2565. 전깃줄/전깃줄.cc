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

    //전선이 엇갈리지 않으려면 A 전봇대를 기준으로 오름차순 정렬 후,
    //B에 걸린 전선도 오름차순이어야 함.
	vector<pair<int, int>> line;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		line.push_back({a, b});
	}
	sort(line.begin(), line.end());

    //dp[i]: 0~i까지 있을 떄, 끝나는 가장 긴 증가하는 부분 수열
	vector<int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int mx = 0;
		for (int j = 0; j < i; j++)
		{
			if(line[j].second < line[i].second)
				mx = max(dp[j], mx);
		}
		dp[i] = mx + 1;
	}

	int ans = 0;
	for(int i=0; i<n; i++)
		ans = max(ans, dp[i]);
	cout << n - ans;
	return 0;
}
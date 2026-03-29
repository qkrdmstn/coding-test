#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	//A 전봇대 기준으로 정렬 후, B 전봇대가 증가하는 수열이면 교차 X
	vector<pair<int, int>> line;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		line.push_back({a, b});
	}
	sort(line.begin(), line.end());

	//dp: B전봇대와 연결된 전깃줄의 위치를 기준으로 가장 긴 증가하는 부분 수열의 크기
	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (line[j].second < line[i].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	//ans: 교차되지 않은 가장 많은 전깃줄
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(dp[i], ans);
	}
	cout << n - ans;
}
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> mat [505];
int dp[505][505];
int n;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mat[i].first >> mat[i].second;
	
	for (int diff = 1; diff < n; diff++)
	{
		for (int st = 0; st + diff < n; st++)
		{
			int ed = st + diff;
			int minVal = 0x3f3f3f3f;
			for (int mid = st; mid < ed; mid++)
			{
				int cal = mat[st].first * mat[mid].second * mat[ed].second;
				minVal = min(minVal, dp[st][mid] + dp[mid + 1][ed] + cal);
			}
			dp[st][ed] = minVal;
		}
	}
	cout << dp[0][n-1];
	return 0;
}
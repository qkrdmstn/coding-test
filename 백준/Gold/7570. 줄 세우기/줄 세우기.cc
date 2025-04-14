#include <iostream>
using namespace std;

int n, lcs;
int dp[1000005];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		dp[num] = dp[num - 1] + 1;
		lcs = max(lcs, dp[num]);
	}

	cout << n - lcs;

	/*
	증가하는 연속된 부분 수열의 최대 길이(lcs)
	ex) 15234 -> 1,2,3,4로 4
	ex) 52413 -> 2,3으로 2
	ex) 1763452 -> 345로 3
	얘네를 제외한 모두를 앞, 뒤로 옮겨야 한다. 따라서, 답은
	n - lcs
	*/
	return 0;
}
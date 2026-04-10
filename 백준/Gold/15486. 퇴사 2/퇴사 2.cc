#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b)
{
	int as, ae, ac;
	int bs, be, bc;
	tie(as, ae, ac) = a;
	tie(bs, be, bc) = b;

	if (ae == be)
		return as < bs;
	return ae < be;
}

int main(void)
{
	int n;
	cin >> n;

	vector<tuple<int, int, int>> meeting(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;
		meeting[i] = { i, i + t - 1, p }; //{상담 시작, 종료, 수익}
	}
	
	//상담 종료일을 기준으로 오름차순 정렬
	sort(meeting.begin() + 1, meeting.end(), cmp);

	vector<int> dp(n+1, 0);
	for (int i = 1; i <= n; i++)
	{
		int st, ed, pay;
		tie(st, ed, pay) = meeting[i];
		if(ed > n) continue;
		dp[ed] = max(dp[st-1] + pay, dp[ed]);
		
		if (i + 1 <= n)
		{
			int nxtMeetingEd = get<1>(meeting[i + 1]);
			for (int j = ed + 1; j <= nxtMeetingEd; j++)
			{
				if(j > n) break;
				dp[j] = dp[ed];
			}
		}
	}
	cout << dp[n];
	return 0;
}

#include <iostream>
using namespace std;

int n;
//d[i] = i번째 날부터 일을 시작했을 때 벌 수 있는 최대 금액
int t[1500005];
int arr[1500005];
int d[1500005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> arr[i];

	for (int i = n; i >= 1; i--) {
		//상담을 퇴사 전까지 끝낼 수 있는지 확인
		if (i + t[i] <= n + 1) {
			//오늘 상담을 안하고 내일 시작하는 것과 하고 끝난 날 또 시작하는 것을 비교
			d[i] = max(d[i + 1], d[i + t[i]] + arr[i]);
		}
		//못 끝내면 시작 X
		else
			d[i] = d[i + 1];
	}

	int ans = d[1];
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]);
	}
	cout << ans;
	return 0;
}
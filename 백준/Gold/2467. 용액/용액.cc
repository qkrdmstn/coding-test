#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans1 = 1e9;
	int ans2 = 1e9;
	for (int i = 0; i < n; i++) {
		int l = lower_bound(a, a + n, -a[i]) - a;
		//index 범위 확인 && 자기 자신인지 확인 && 최소값 확인
		if (l + 1 < n && l + 1 != i && abs(a[i] + a[l + 1]) < abs(ans1 + ans2)) {
			ans1 = a[i];
			ans2 = a[l+1];
		}
		if (l < n && l != i && abs(a[i] + a[l]) < abs(ans1 + ans2)) {
			ans1 = a[i];
			ans2 = a[l];
		}
		if (l - 1 >= 0 && l - 1 != i && abs(a[i] + a[l - 1]) < abs(ans1 + ans2)) {
			ans1 = a[i];
			ans2 = a[l - 1];
		}			
	}
	if (ans1 > ans2) swap(ans1, ans2);
	cout << ans1 << ' ' << ans2;
	return 0;

	/*
	lower_bound: key 값과 같거나 큰 값이 배열에서 처음으로 등장하는 위치
	upper_bound: key 값을 초과하는 값이 배열에서 처음으로 등장하는 위치
	*/
}
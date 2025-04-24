#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[10005];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int u = upper_bound(a + j + 1, a + n, -a[i] - a[j]) - a;
			int l = lower_bound(a + j + 1, a + n, -a[i] - a[j]) - a;
			ans += u - l;
		}
	}
	cout << ans;
	return 0;

	/*
	2명을 지정하고 나머지 0이 되도록 할 수 있는 나머지 한 명을 이분탐색으로 찾기.
	같은 실력인 애가 여러명일 수도 있으므로, lower, upper bound를 활용
	*/
}
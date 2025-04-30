#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100'005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	int ans = 2'000'000'001;

	int st = 0, en = 0;
	for (st = 0; st < n; st++) {
		while (a[en] - a[st] < m)
			en++;
		if (en >= n)
			break;

		ans = min(ans, a[en] - a[st]);
	}
	cout << abs(ans);

	/*
	투포인터 풀이법
	*/
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int l[1000005];

int solve(int len)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += l[i] / len;
	return cnt;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i];

	int s = 0;
	int e = 1000000000 ;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		if (solve(mid) >= m)
			s = mid;
		else
			e = mid - 1;
	}
	cout << s;
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[10005];
int total;

bool solve(int limit)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += min(a[i], limit);
	return sum <= total;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	int s = 1, e = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		e = max(a[i], e);
	}
	cin >> total;

	while (s < e){
		int m = (s + e + 1) / 2;
		if (solve(m))
			s = m;
		else
			e = m - 1;
	}
	cout << s;
	return 0;
}
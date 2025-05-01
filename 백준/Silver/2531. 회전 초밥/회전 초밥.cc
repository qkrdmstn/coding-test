#include <iostream>
using namespace std;

int n, d, k, c;
int a[30005 * 2];
int ateCount[3001];
int ateKind, ans;

void eat(int num)
{
	if (ateCount[num] == 0) {
		ateKind++;
		ans = max(ateKind, ans);
	}
	ateCount[num]++;
}

void overeat(int num)
{
	ateCount[num]--;
	if (ateCount[num] == 0)
		ateKind--;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[n + i] = a[i];
	}

	ateCount[c]++;
	ateKind = 1;
	ans = 1;

	for (int i = 0; i < n * 2; i++) {
		if (i >= k) overeat(a[i - k]);
		eat(a[i]);
	}
	cout << ans;
	return 0;
}

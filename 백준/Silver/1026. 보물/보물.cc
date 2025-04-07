#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51];
int b[51];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + n);

	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[i] * b[n - i - 1];
	cout << s;
	return 0;
}
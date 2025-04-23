#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[500005];

int lowerIndex(int num)
{
	int start = 0;
	int end = n;
	while (start < end) {
		int mid = (start + end) / 2;
		if (num <= a[mid])
			end = mid;
		else
			start = mid + 1;
	}
	return start;
}

int upperIndex(int num)
{
	int start = 0;
	int end = n;
	while (start < end) {
		int mid = (start + end) / 2;
		if (num < a[mid])
			end = mid;
		else
			start = mid + 1;
	}
	return start;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << upperIndex(num) - lowerIndex(num) << ' ';
	}

	return 0;
}
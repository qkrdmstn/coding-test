#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100005];

bool find(int num)
{
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] == num)
			return 1;
		else if (num < a[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return 0;
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
		cout << find(num) << '\n';
	}

	return 0;
}
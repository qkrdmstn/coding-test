#include <iostream>
using namespace std;

int n;
int arr[100005];

int LowerBound(int num)
{
	int st = 0;
	int ed = n - 1;
	while (st < ed) {
		int mid = (st + ed) / 2;
		if (arr[mid] < num) st = mid + 1;
		else ed = mid;
	}

	return st;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans1 = 1e9; 
	int ans2 = 1e9;
	for (int i = 0; i < n; i++) {
		int l = LowerBound(-arr[i]);

		if (l - 1 != i && l - 1 >= 0 && abs(arr[i] + arr[l - 1]) < abs(ans1 + ans2)) {
			ans1 = arr[i];
			ans2 = arr[l - 1];
		}

		if (l != i && abs(arr[i] + arr[l]) < abs(ans1 + ans2)) {
			ans1 = arr[i];
			ans2 = arr[l];
		}

		if (l + 1 != i && l + 1 < n && abs(arr[i] + arr[l + 1]) < abs(ans1 + ans2)) {
			ans1 = arr[i];
			ans2 = arr[l + 1];
		}
	}

	if (ans1 > ans2) swap(ans1, ans2);
	cout << ans1 << ' ' << ans2;
	return 0;
}
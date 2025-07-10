#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1000005];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> v(arr, arr + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++)
		arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	return 0;
}
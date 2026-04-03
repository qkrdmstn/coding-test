#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> arr(n*n);
	for (int i = 0; i < n * n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end(), greater<int>());
	cout << arr[n-1];
}
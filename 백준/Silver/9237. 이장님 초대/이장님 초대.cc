#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end(), greater<int>());
	for(int i=0; i<n; i++)
		arr[i] += i + 1;

	sort(arr.begin(), arr.end(), greater<int>());
	cout << arr[0] + 1;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nA, nB;
int a[500005];
int b[500005];
vector<int> ans;

bool find(int arr[], int len, int num)
{
	int s = 0;
	int e = len - 1;

	while (s <= e) {
		int m = (s + e) / 2;
		if (arr[m] == num)
			return true;
		else if (num < arr[m])
			e = m - 1;
		else
			s = m + 1;
	}
	return false;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> nA >> nB;
	for (int i = 0; i < nA; i++)
		cin >> a[i];
	for (int i = 0; i < nB; i++)
		cin >> b[i];
	sort(a, a + nA);
	sort(b, b + nB);

	for (int i = 0; i < nA; i++) {
		if (!find(b, nB, a[i]))
			ans.push_back(a[i]);
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';

	return 0;
}
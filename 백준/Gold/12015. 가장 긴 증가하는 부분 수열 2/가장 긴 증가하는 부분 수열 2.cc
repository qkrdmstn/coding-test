#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[1000005];
vector<int> ans;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ans.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (ans.back() < a[i]) {
			ans.push_back(a[i]);
		}
		else if (ans.back() > a[i]) {
			int l = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
			ans[l] = a[i];
		}
	}

	cout << ans.size() << '\n';
	return 0;
}
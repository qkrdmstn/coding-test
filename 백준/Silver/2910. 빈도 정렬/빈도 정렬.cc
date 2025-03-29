#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<pair<int, int>> v;

bool Compare(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first > b.first;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		bool flag = false;
		for (auto& a : v) {
			if (a.second == num) {
				flag = true;
				a.first++;
				break;
			}
		}
		if(!flag)
			v.push_back({1, num});
	}

	stable_sort(v.begin(), v.end(), Compare);

	for (auto a : v)
		while (a.first--) cout << a.second << ' ';
	return 0;
}
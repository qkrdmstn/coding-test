#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

#define X first
#define Y second

unordered_map<string, int> order;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
	return a.Y < b.Y;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, l;
	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		string num;
		cin >> num;

		if (order.find(num) != order.end())
			order.erase(num);
		order.insert({ num, i });
	}

	vector<pair<string, int>> v(order.begin(), order.end());
	sort(v.begin(), v.end(), cmp);

	int end = k;
	if (v.size() < k)
		end = v.size();

	for (int i = 0; i < end; i++)
		cout << v[i].X << '\n';
	return 0;
}
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<string> s;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, c;
		cin >> name >> c;
		if (c == "enter") s.insert(name);
		else s.erase(name);
	}

	vector<string> v(s.begin(), s.end());
	sort(v.begin(), v.end(), greater<string>());

	for (auto x : v) cout << x << '\n';
	return 0;
}
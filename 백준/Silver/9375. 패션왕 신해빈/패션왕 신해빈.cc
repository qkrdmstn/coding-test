#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		unordered_map<string, int> memo;
		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;
			if (memo.find(type) != memo.end())
				memo[type]++;
			else
				memo.insert({ type, 1 });
		}
		int ans = 1;
		for (auto m : memo)
			ans *= m.second + 1;
		cout << ans - 1 << '\n';
	}

	return 0;
}
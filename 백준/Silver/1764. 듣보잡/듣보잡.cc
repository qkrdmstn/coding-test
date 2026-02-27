#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	unordered_set<string> listen;
	unordered_set<string> look;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		listen.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		look.insert(s);
	}

	vector<string> result;
	if (n < m)
	{
		for (auto name : listen)
		{
			if(look.find(name) != look.end())
				result.push_back(name);
		}
	}
	else
	{
		for (auto name : look)
		{
			if (listen.find(name) != listen.end())
				result.push_back(name);
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for(auto r: result)
		cout << r << '\n';
	return 0;
}
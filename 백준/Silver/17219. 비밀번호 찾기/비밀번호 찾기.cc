#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<string, string> memo;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string add, pass;
		cin >> add >> pass;
		memo.insert({ add,pass });
	}

	for (int i = 0; i < m; i++) {
		string target;
		cin >> target;
		cout << memo[target] << '\n';
	}
	return 0;
}
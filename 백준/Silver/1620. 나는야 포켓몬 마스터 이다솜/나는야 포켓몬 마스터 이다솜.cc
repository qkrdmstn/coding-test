#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> num;
string name[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> name[i];
		num[name[i]] = i;
	}

	for (int i = 0; i < m; i++) {
		string query;
		cin >> query;
		if (isdigit(query[0]))
			cout << name[stoi(query)] << '\n';
		else
			cout << num[query] << '\n';
	}
	return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<string, string> m2t;
unordered_map<string, vector<string>> t2m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string teamName;
		int numOfMem;
		cin >> teamName >> numOfMem;

		for (int j = 0; j < numOfMem; j++) {
			string name;
			cin >> name;

			m2t[name] = teamName;
			t2m[teamName].push_back(name);
		}
		sort(t2m[teamName].begin(), t2m[teamName].end());
	}


	for (int i = 0; i < m; i++) {
		string quiz;
		int type;
		cin >> quiz >> type;
		if (type)
			cout << m2t[quiz] << '\n';
		else
			for (string m : t2m[quiz]) cout << m << '\n';
	}
	return 0;
}
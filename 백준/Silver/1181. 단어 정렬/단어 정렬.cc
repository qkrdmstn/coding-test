#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> v;
string word;

bool Compare(string a, string b)
{
	if (a.length() < b.length())
		return true;
	else if (a.length() > b.length())
		return false;
	else {
		return a < b;
	}
}
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		v.push_back(word);
	}

	sort(v.begin(), v.end(), Compare);

	string before = "";
	for (int i = 0; i < n; i++) {
		if (v[i] == before)
			continue;
		cout << v[i] << '\n';
		before = v[i];
	}

	return 0;
}
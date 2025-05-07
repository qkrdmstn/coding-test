#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> set;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int st = 0; st < s.length(); st++) {
		for (int ed = st; ed < s.length(); ed++) {
			string sub;
			for (int i = st; i <= ed; i++)
				sub += s[i];
			set.insert(sub);
		}
	}

	cout << set.size();
	return 0;
}
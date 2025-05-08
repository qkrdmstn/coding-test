#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> enterList;
unordered_set<string> exitList;

int timeToInteger(string time)
{
	string h = time.substr(0, 2);
	string m = time.substr(3, 2);

	int hour = stoi(h);
	int minutes = stoi(m);

	return (hour * 60) + minutes;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string st, ed1, ed2;
	cin >> st >> ed1 >> ed2;

	int s = timeToInteger(st);
	int e1 = timeToInteger(ed1);
	int e2 = timeToInteger(ed2);

	while (true) {
		string t, name;
		cin >> t >> name;
		if (cin.eof()) break;

		if (timeToInteger(t) <= s) {
			enterList.insert(name);
		}
		else if (timeToInteger(t) >= e1 && timeToInteger(t) <= e2) {
			if(enterList.find(name) != enterList.end())
				exitList.insert(name);
		}

	}

	cout << exitList.size() << '\n';
	return 0;
}
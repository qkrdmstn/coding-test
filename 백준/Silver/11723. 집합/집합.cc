#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<int> s;
	while (n--)
	{
		string op;
		cin >> op;
		if (op == "add")
		{
			int num;
			cin >> num;
			if(s.find(num) == s.end()) s.insert(num);
		}
		else if (op == "remove")
		{
			int num;
			cin >> num;
			if(s.find(num) != s.end()) s.erase(num);
		}
		else if (op == "check")
		{
			int num;
			cin >> num;
			if(s.find(num) != s.end()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (op == "toggle")
		{
			int num;
			cin >> num;
			if(s.find(num) != s.end()) s.erase(num);
			else s.insert(num);
		}
		else if (op == "all")
		{
			for (int i = 1; i <= 20; i++)
				s.insert(i);
		}
		else if (op == "empty")
		{
			for(int i=1; i<=20; i++)
				s.erase(i);
		}
	}

	return 0;
}
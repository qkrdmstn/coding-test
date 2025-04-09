#include <iostream>
#include <string>
using namespace std;

string s;
int count0, count1;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> s;
	
	char before = s[0];
	if (s[0] == '0')
		count0++;
	else
		count1++;

	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] != s[i]) {
			if (s[i] == '0')
				count0++;
			else
				count1++;
		}
	}

	cout << min(count0, count1);
	return 0;
}
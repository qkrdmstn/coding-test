#include<iostream>
#include<string>
using namespace std;


int main()
{
	string s = "\0";
	char c;
	int n, b;
	cin >> n >> b;

	while (n / b >= 0)
	{
		if (n % b >= 10)
		{
			s += (n % b) + 55;
		}
		else
		{
			s += (n % b) + 48;
		}
		if (n / b == 0)
			break;
		n /= b;
	}

	for(int i = s.length() - 1; i>=0; i--)
	{
		cout << s[i];
	}


}

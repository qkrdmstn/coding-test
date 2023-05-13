#include<iostream>
#include<string>
using namespace std;

int Trans(char a);

int main()
{
	int s = 0;
	string a;
	cin >> a;

	for (int i = 0; i < a.length(); i++)
	{
		s += Trans(a[i]) + 1;
	}
	cout << s;

	return 0;
}

int Trans(char a)
{
	if (a == 65 || a == 66 || a == 67)
		return 2;
	else if (a == 68 || a == 69 || a == 70)
		return 3;
	else if (a == 71 || a == 72 || a == 73)
		return 4;
	else if (a == 74 || a == 75 || a == 76)
		return 5;
	else if (a == 77 || a == 78 || a == 79)
		return 6;
	else if (a == 80 || a == 81 || a == 82 || a == 83)
		return 7;
	else if (a == 84 || a == 85 || a == 86)
		return 8;
	else if (a == 87 || a == 88 || a == 89 || a == 90)
		return 9;

}
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int c = 0;
	string a;

	getline(cin, a);

	for (int i = 0; i <= a.length(); i++)
	{
		if (a[i] == ' ')
			c++;
	}
	if (a[0] == ' ')
		c--;
	if (a[a.length()-1] == ' ')
		c--;
	cout << c + 1 << endl;;

	
	return 0;
}
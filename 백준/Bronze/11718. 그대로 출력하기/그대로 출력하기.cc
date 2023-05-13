#include<iostream>
#include<string>
using namespace std;

int main()
{
	int c = 0;
	string a;

	while (1)
	{
		getline(cin, a);
		if (a == "")
			break;
		cout << a << endl;
	}

	
	return 0;
}
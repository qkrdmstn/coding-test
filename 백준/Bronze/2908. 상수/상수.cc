#include<iostream>
#include<string>
using namespace std;

int main()
{
	int c = 0;
	string a, b, r;
	cin >> a >> b;

	for (int i = 2; i >= 0; i--)
	{
		if (a[i] > b[i])
		{
			r = a;
			break;
		}
		else if (a[i] < b[i])
		{
			r = b;
			break;
		}
	}
	
	cout << r[2] << r[1] << r[0];

	
	return 0;
}
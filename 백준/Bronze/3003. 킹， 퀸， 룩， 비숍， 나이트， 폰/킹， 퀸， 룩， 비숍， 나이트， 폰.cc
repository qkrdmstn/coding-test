#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a[6];
	int b[6] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < 6; i++)
	{
		a[i] = b[i] - a[i];
		if (i == 5)
		{
			cout << a[i];
			continue;
		}
		cout << a[i] << " ";

	}

	return 0;
}

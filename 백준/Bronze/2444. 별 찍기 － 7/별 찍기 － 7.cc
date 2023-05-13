#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= (2 * n - 1); i++)
	{
		if (i <= n)
		{
			for (int k = 0; k < n - i; k++)
				cout << " ";

			for (int j = 0; j < (2 * i - 1); j++)
				cout << "*";

			cout << endl;
		}
		else
		{
			for (int k = 0; k < i - n; k++)
				cout << " ";

			for (int j = 0; j < 2*(2 * n - i)-1; j++)
				cout << "*";

			cout << endl;
		}
		
	}


	return 0;
}

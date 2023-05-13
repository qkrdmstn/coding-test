#include<iostream>
using namespace std;

int main()
{
	int n, r;
	char a[21];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> r >> a;

		int k = 0;
		while (a[k] != '\0')
		{
			for (int j = 0; j < r; j++)
			{
				cout << a[k];
			}
			k++;
		}	
		cout << endl;
	}
	return 0;
}
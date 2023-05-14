#include<iostream>
using namespace std;

int main()
{
	char a[1000];
	int n, j;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		j = 0;
		while (a[j] != '\0')
		{
			j++;
		}

		cout << a[0] << a[j - 1] << endl;
	}

	
	return 0;
}
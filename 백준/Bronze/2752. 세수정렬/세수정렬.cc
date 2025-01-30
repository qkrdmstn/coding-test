#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int a[3], b[3];
	for (int i = 0; i < 3; i++)
		cin >> a[i];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a [j+ 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 3; i++)
		cout << a[i] << " ";
	return 0;
}
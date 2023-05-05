#include<iostream>
using namespace std;

int main(void)
{
	int a[9], index, max;
	max = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		if (a[i] > max)
		{
			max = a[i];
			index = i;
		}
	}

	cout << max << endl;
	cout << index + 1;
	
	return 0;
}
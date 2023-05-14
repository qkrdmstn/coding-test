#include<iostream>
using namespace std;


int main(void)
{
	bool a[31] = { false };
	int c;
	
	for (int i = 1; i <= 28; i++)
	{
		cin >> c;
		a[c] = true;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (a[i] == false)
			cout << i << endl;
	}
	return 0;
}

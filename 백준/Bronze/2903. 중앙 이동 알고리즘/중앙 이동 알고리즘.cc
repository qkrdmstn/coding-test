#include<iostream>
#include<string>
using namespace std;

int pow(int a, int b);

int main()
{
	int n, s = 2;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		s += pow(2, i);
	}

	cout << pow(s, 2);
	return 0;
}

int pow(int a, int b)
{
	int s = a;
	for (int i = 1; i < b; i++)
		a = a * s;
	if (b == 0)
		return 1;
	return a;
}
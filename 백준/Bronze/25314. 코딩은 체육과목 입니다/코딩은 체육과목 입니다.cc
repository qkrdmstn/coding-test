#include<iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int x = n / 4;
	for (int i = 0; i < x; i++)
		cout << "long ";
	cout << "int";

	return 0;
}
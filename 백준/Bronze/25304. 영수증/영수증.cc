#include<iostream>
using namespace std;

int main(void)
{
	int price, n, a, b;
	int sum = 0;
	cin >> price >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		sum += (a * b);
	}

	if (sum == price)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
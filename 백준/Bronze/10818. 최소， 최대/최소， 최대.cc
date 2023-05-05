#include<iostream>
using namespace std;

int main(void)
{
	int n, a, min, max;
	cin >> n ;

	cin >> a;
	min = a;
	max = a;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a;
		if (a > max)
			max = a;
		else if (a < min)
			min = a;
	}

	cout << min << " " << max;
	
	return 0;
}
#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int min = 101;
	int sum = 0;
	for (int i = 0; i < 7; i++) 
	{
		int num;
		cin >> num;

		if (num % 2 == 1)
		{
			sum += num;
			if (num < min)
				min = num;
		}
	}

	if (sum == 0)
		cout << "-1";
	else
		cout << sum << "\n" << min;
	return 0;
}
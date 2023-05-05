#include<iostream>
using namespace std;

int main(void)
{
	float a[1000];
	float n, max = 0;
	float sum = 0.0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > max)
			max = a[i];
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = (a[i] / max) * 100;
		sum += a[i];
	}
	cout << sum / (float)n;
	return 0;
}
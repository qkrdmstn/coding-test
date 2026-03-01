#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> d(50001, 100);
	int n;
	cin >> n;

	for(int i=1; i*i<=n; i++)
		d[i*i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			d[i] = min(d[i], d[i-j*j] + 1);
		}
	}

	cout << d[n];
	return 0;
}
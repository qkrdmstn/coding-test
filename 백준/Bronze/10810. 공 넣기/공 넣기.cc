#include<iostream>
using namespace std;

int main(void)
{
	int a[100] = { 0 }, n, m;
	int x, y, z;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		while (x <= y)
		{
			a[x] = z;
			x++;
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";

	return 0;
}
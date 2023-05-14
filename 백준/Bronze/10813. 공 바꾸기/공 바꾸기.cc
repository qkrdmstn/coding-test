#include<iostream>
using namespace std;

void Swap(int& a, int& b);

int main(void)
{
	int n, m;
	int a[100];
	int x, y;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		Swap(a[x], a[y]);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}

void Swap(int& a, int& b)
{
	int s;
	s = a;
	a = b;
	b = s;
}
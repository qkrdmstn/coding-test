#include<iostream>
using namespace std;

void Swap(int a[], int k, int j);

int main(void)
{
	int n, m, a[100];
	cin >> n >> m;
	int k, j;
	for (int i = 1; i <= n; i++)
		a[i] = i;
	for (int i = 0; i < m; i++)
	{
		cin >> k >> j;
		Swap(a, k, j);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
}

void Swap(int a[], int k, int j)
{
	int b[100];
	int x = j;
	for (int i = k; i <= j; i++)
	{
		b[i] = a[i];
	}
	for (int i = k; i <= j; i++)
	{
		a[i] = b[x];
		x--;
	}
}
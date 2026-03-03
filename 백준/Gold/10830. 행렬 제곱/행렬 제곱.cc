#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix Product(matrix& a, matrix& b, int n)
{
	matrix r(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % 1000;
			}
		}
	}

	return r;
}

matrix Pow(matrix& a, ll exp, int n)
{
	if(exp == 1) return a;
	if (exp % 2 == 0)
	{
		matrix half = Pow(a, exp/2, n);
		return Product(half, half, n);
	}
	else
	{
		matrix half = Pow(a, (exp-1)/2, n);
		matrix tmp = Product(half, half, n);
		return Product(tmp, a, n);
	}
}

int main(void)
{
	int n;
	ll b;
	cin >> n >> b;

	matrix a(n, vector<ll>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			a[i][j] = num % 1000;;
		}
	}

	matrix result = Pow(a, b, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << result[i][j] <<" ";
		cout << '\n';
	}
	return 0;
}
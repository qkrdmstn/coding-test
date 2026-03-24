#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Mat;
const int MOD = 1000;

Mat Product(Mat a, Mat b, int n)
{
	Mat res(n, vector<ll>(n));
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
			}
		}
	}
	return res;
}

Mat Pow(Mat m, ll exp, int n)
{
	if(exp == 1) return m;
	
	if (exp % 2 == 0)
	{
		Mat half = Pow(m, exp / 2, n);
		return Product(half, half, n);
	}
	else
	{
		Mat half = Pow(m, (exp - 1) / 2, n);
		Mat tmp = Product(half, half, n);
		return Product(tmp, m, n);
	}
}

int main(void)
{
	int n;
	ll b;
	cin >> n >> b;

	Mat m(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			m[i][j] = num % MOD;
		}
	}

	Mat res = Pow(m, b, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << res[i][j]<< " ";
		cout << "\n";
	}
	return 0;
}
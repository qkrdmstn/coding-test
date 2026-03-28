#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Mat;
const int MOD = 1000;

Mat Product(Mat a, Mat b, int n)
{
	Mat r(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				r[i][j] = (r[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
		}
	}
	return r;
}

Mat Pow(Mat a, ll exp, int n)
{
	if(exp == 1) return a;
	Mat half = Pow(a, exp/2, n);
	if (exp % 2 == 0)
		return Product(half, half, n);
	else
	{
		Mat tmp = Product(half, half, n);
		return Product(tmp, a, n);
	}
}

int main(void)
{
	int n;
	ll exp;
	cin >> n >> exp;

	Mat a(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			a[i][j] %= MOD;
		}
	}

	Mat res = Pow(a, exp, n);
	for (int i = 0; i < n; i++)
	{
		for(int j=0; j<n; j++)
			cout << res[i][j] << " ";
		cout << "\n";
	}


	return 0;
}
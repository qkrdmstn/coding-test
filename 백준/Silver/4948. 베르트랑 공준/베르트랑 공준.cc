#include <iostream>
#include <vector>
using namespace std;

void RangePrime(int n, vector<bool>& isPrime)
{
	for (int i = 2; i * i <= n; i++)
	{
		for (int j = i * i; j <= n; j += i)
			isPrime[j] = false;
	}
}

int Count(int n, vector<bool>& isPrime)
{
	int cnt = 0;
	for(int i= n+1; i<=2*n; i++)
		cnt += isPrime[i];
	return cnt;
}

int main(void)
{
	vector<bool> isPrime(123457*2, true);
	RangePrime(123456*2, isPrime);

	while (true)
	{
		int n;
		cin >> n;
		if(n == 0) break;
		cout << Count(n, isPrime) << "\n";
	}
	return 0;
}
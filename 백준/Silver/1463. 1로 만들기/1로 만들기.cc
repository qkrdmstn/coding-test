#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int main(void)
{
	int n;
	cin >> n;
	vector<int> d(n + 1, INF);

	d[1] = 0;
	for(int i=2; i<=n; i++)
	{
		if(i % 2 == 0)
			d[i] = min(d[i], d[i/2] + 1);
		if(i % 3 == 0)
			d[i] = min(d[i], d[i/3] + 1);
		if(i > 1)
			d[i] = min(d[i], d[i-1] + 1);
	}
	cout << d[n];
}
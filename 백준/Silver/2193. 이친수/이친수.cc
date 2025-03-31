#include <iostream>
using namespace std;
#define X first
#define Y second

int n;
//d[n]: n번째 자리의 이친수의 수
long long d[92];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i <= n; i++)
		d[i] = d[i-1] + d[i-2];
	cout << d[n];

	//d[i-1].X + d[i-1].Y = d[i-1], d[i-1].X = d[i-2].X + d[i-2].Y = d[i-2] 
	//=> d[i] = d[i-1] + d[i-2]도 같은 식
	return 0;
}
#include <iostream>
using namespace std;
#define X first
#define Y second

int n;
//d[n]: n번째 자리의 끝자리가 X:0/Y:1 인 경우의 수
pair<long, long> d[92];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	d[1] = { 0,1 };
	d[2] = { 1,0 };

	//d[i-1]로 d[i]를 만드는 과정에서 끝이 0으로 끝나는 자리엔 1과 0이 모두 올 수 있고,
	//1로 끝나는 자리엔 1만 올 수 있다.
	for (int i = 3; i <= n; i++)
		d[i] = { d[i - 1].X + d[i - 1].Y , d[i - 1].X};
	cout << d[n].X + d[n].Y;

	//d[i-1].X + d[i-1].Y = d[i-1], d[i-1].X = d[i-2].X + d[i-2].Y = d[i-2] 
	//=> d[i] = d[i-1] + d[i-2]도 같은 식
	return 0;
}
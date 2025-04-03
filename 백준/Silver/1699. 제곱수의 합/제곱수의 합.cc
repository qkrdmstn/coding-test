#include <iostream>
using namespace std;

int n;
int d[100005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		//자연수 i는 1의 제곱 i개로 표현 가능
		d[i] = i;
		for (int j = 1; j * j <= i; j++) {
			//i보다 작은 제곱수 j*j를 순회하며 i를 합으로 표현
			d[i] = min(d[i], 1 + d[i - j * j]);
		}
	}
	cout << d[n];
	return 0;
}
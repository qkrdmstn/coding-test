#include <iostream>
using namespace std;

int t, n;
int coin[20];
//d[i] = i원을 만들 수 있는 경우의 수
int d[100005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> coin[i];

		int m;
		cin >> m;

		//배열 초기화
		for (int i = 0; i <= m; i++)
			d[i] = 0;

		d[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= m; j++) {
				d[j] += d[j - coin[i]];
			}
		}
		cout << d[m] << '\n';
	}

	// d[j] += d[j-coin[i]]
	// -> j원: i원 동전 하나 + (j-coin[i])원을 만들 수 있는 방법의 수로 만들 수 있음
	// 자신보다 작은 모든 coin에 대해 반복
	return 0;
}
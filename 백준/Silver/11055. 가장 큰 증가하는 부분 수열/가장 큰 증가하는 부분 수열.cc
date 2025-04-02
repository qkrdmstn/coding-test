#include <iostream>
using namespace std;
#define PRE first
#define VAL second

int n;
//d[i] = {가장 최근에 선택한 원소,  i번째 항으로 끝나는 증가하는 부분 수열의 합 중 최대}
int d[1002];
int arr[1002];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i] = arr[i];
	}

	d[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				int val = d[j] + arr[i];
				if (val > d[i])
					d[i] = val;
			}
		}
	}

	int ans = d[1];
	for (int i = 2; i <= n; i++) {
		ans = max(d[i], ans);
	}
	cout << ans;
	return 0;
}
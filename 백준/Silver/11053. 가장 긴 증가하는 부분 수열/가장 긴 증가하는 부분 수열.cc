#include <iostream>
using namespace std;

int n;
//d[i] = {i번째 항으로 끝나는 증가하는 부분 수열의 원소의 길이 중 최대}
int d[1002];
int arr[1002];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		d[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			//증가하는 수열 확인
			if (arr[j] < arr[i]) {
				//길이 증가
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int ans = d[0];
	for (int i = 1; i < n; i++) {
		ans = max(d[i], ans);
	}
	cout << ans;
	return 0;
}
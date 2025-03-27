#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[100001];
int mxCnt, cnt = 1;
long long mxVal = -2e62 - 1;


int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 1; i < n; i++) {
		if (arr[i - 1] == arr[i])
			cnt++;
		else {
			if (cnt > mxCnt) {
				mxVal = arr[i-1];
				mxCnt = cnt;
			}
			cnt = 1;
		}
	}
	if (cnt > mxCnt) mxVal = arr[n - 1];
	cout << mxVal;

	return 0;
}
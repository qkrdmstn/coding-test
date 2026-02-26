#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int main(void)
{
	int n;
	cin >> n;
	vector<int> arr(n + 1, 0);
	//d[i]: i번째 계단을 밟지 않을 때 놓친 점수가 최솟값.
	vector<int> d(n + 1, 0);

	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		total += arr[i];
	}

	d[1] = arr[1];
	d[2] = arr[2];
	//i번째를 밟지 않으려면 i-1번째를 무조건 밟아야 하고, i-1번째를 무조건 밟으려면 i-2와 i-3번째 둘 중 하나는 밟지 않아야 한다.
	for(int i=3; i<=n; i++)
		d[i] = min(d[i-2], d[i-3]) + arr[i];
	//마지막 계단을 무조건 밟으려면 n-1 번째 또는 n-2번째를 밟지 않아야 한다.
	cout << total - min(d[n-1], d[n-2]);
}
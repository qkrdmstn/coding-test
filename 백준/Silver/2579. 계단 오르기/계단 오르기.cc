#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int main(void)
{
	int n;
	cin >> n;
	vector<int> arr(n + 1, 0);
	
	//d[i][0]: i-1번째를 밟지 않고 i번째에 도착하는 최댓값
	//d[i][1]: i-1번째를 밟고 i번째에 도착하는 최댓값
	vector<vector<int>> d(n + 1, vector<int>(2, 0));

	for (int i = 1; i <= n; i++) 
		cin >> arr[i];

	d[1][0] = d[1][1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		//i-1번째를 밟으려면 i-1번째를 밟았을 때 i-2번째를 밟지 않아야 함.
		d[i][1] = d[i-1][0] + arr[i];
		//i-1번째를 밟지 않는다면 i-2번째는 밟아도/밟지 않아도 무관함
		d[i][0] = max(d[i-2][1], d[i-2][0]) + arr[i];
	}
	cout << max(d[n][0], d[n][1]);
}
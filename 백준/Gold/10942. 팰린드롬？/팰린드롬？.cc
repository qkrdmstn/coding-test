#include <iostream>
#include <vector>
using namespace std;

int main(void)
{

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> arr(n+1);
	vector<vector<int>> d(n+1, vector<int>(n + 1, 0));
	for(int i=1; i<=n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		//길이가 1인 수열은 무조건 팰린드롬
		d[i][i] = 1;
		//길이가 2인 수열은 앞뒤가 같으면 팰린드롬
		if(i+1 <= n && arr[i] == arr[i+1])
			d[i][i+1] = 1;
	}

	//길이가 3인 팰린드롬은 시작과 끝이 같고 그 사이 수열이 팰린드롬이면 팰린드롬이다.
	for (int diff = 2; diff < n; diff++)
	{
		for (int i = 1; i <= n - diff; i++)
		{
			int j=i+diff;
			if(arr[i]==arr[j] && d[i+1][j-1] == 1)
				d[i][j] = 1;
		}
	}

	int m;
	cin >> m;
	while (m--)
	{
		int s, e;
		cin >> s >> e;
		cout << d[s][e]<<"\n";
	}
	return 0;
}
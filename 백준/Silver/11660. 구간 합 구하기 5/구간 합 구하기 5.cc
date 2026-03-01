#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<vector<int>> d(n+1, vector<int>(n + 1, 0));
	vector<vector<int>> arr(n+1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for(int j=1; j<=n; j++)
			cin >> arr[i][j];
	}

	//(1,1) ~ (i,j)까지의 합 저장
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + arr[i][j];
	}

	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// (x2,y2)까지의 합 - (x2,y1-1)까지의 합 - (x1-1,y2)까지의 합
		//+ 앞의 두 단계의 빼기에서 중복으로 빠진 (x1-1,y1-1)까지의 합을 다시 더해준다.
		cout << d[x2][y2] - d[x2][y1-1] - d[x1-1][y2] + d[x1-1][y1-1] << '\n';
	}
	return 0;
}
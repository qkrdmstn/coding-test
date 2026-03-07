#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<string> s(n);
	for(int i=0; i<n; i++)
		cin >> s[i];

	//d[i][j]: i,j를 오른쪽하단 꼭짓점으로 하는 가장 큰 정사각형의 한 변의 길이
	vector<vector<int>> d(n, vector<int>(m, 0));

	//위, 왼쪽 가장자리는 최대 1의 크기
	for(int i=0; i<n; i++)
		d[i][0] = s[i][0] - '0';
	for (int i = 0; i < m; i++)
		d[0][i] = s[0][i] - '0';

	//i,j는 위, 왼쪽, 왼쪽 위의 정사각형 크기 중 가장 작은 것 + 1
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (s[i][j] == '1')
				d[i][j] = min(d[i-1][j], min(d[i][j-1], d[i-1][j-1])) + 1;
			else
				d[i][j] = 0;
		}
	}

	//가장 변의 길이가 긴 정사각형의 넓이 계산
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j=0; j<m; j++)
			ans = max(ans, d[i][j]);
	}
	cout << ans * ans;
	return 0;
}
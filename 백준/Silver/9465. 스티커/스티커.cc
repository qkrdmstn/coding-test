#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		//d[i][j]: i행 j열에 있는 스티커를 땔 때 모을 수 있는 최대 점수
		vector<vector<int>> d(2, vector<int>(n + 1, 0));
		vector<vector<int>> arr(2, vector<int>(n + 1));
		for (int i = 0; i < 2; i++)
		{
			for(int j=1; j<=n; j++)
				cin >> arr[i][j];
		}

		//초기값 설정
		d[0][1] = arr[0][1];
		d[1][1] = arr[1][1];
		for (int i = 2; i <= n; i++)
		{
			//0,i번째 스티커를 때면, i-1열의 반대 스티커를 때거나
			//i-2열의 반대 스티커를 때는 경우가 존재. 둘 중 더 큰 것을 선택
			d[0][i] = max(d[1][i-1], d[1][i-2])+ arr[0][i];
			d[1][i] = max(d[0][i-1], d[0][i-2])+ arr[1][i];
		}
		cout << max(d[0][n],d[1][n]) << '\n';
	}
	return 0;
}
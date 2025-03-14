#include <iostream>
using namespace std;

int n, ans;
int arr[21][21];
int arrCpy[21][21];

//시계방향 회전
void Rotate()
{
	int temp[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = arrCpy[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arrCpy[i][j] = temp[n-1-j][i];
		}
	}
}

//dir 0: 왼쪽, 1: 아래쪽, 2: 오른쪽, 3: 위쪽
void Move1D(int rowNum, int dir)
{
	//방향에 맞춰 회전
	for (int i = 0; i < dir; i++)
		Rotate();

	int result[21] = {};
	int point = 0;
	for (int cur = 0; cur < n; cur++) {
		if (arrCpy[rowNum][cur] == 0)
			continue;
		if (result[point] == 0) {
			result[point] = arrCpy[rowNum][cur];
		}
		else if (result[point] == arrCpy[rowNum][cur]) {
			result[point++] += arrCpy[rowNum][cur];
		}
		else if (result[point] != arrCpy[rowNum][cur]) {
			result[++point] = arrCpy[rowNum][cur];
		}
	}
	for (int i = 0; i < n; i++) {
		arrCpy[rowNum][i] = result[i];
	}

	//원상 복귀
	for (int i = 0; i < 4-dir; i++)
		Rotate();
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//4진수를 활용해 각 경우의 수를 순회 ex) 0 0 0 0 0, 0 0 0 0 1 ...
	for (int binary = 0; binary < (1 << 2 * 5); binary++) {
		//실제로 시뮬레이션 할 배열 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arrCpy[i][j] = arr[i][j];
			}
		}

		int temp = binary;
		for (int i = 0; i < 5; i++) {
			int dir = temp % 4;
			temp /= 4;

			for (int i = 0; i < n; i++)
				Move1D(i, dir);

			//가장 큰 블록 찾기
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (ans < arrCpy[i][j])
						ans = arrCpy[i][j];
				}
			}
		}
	}

	cout << ans;
	return 0;
}
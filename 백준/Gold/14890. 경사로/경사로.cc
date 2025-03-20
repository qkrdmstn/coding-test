#include <iostream>
using namespace std;

int n, l, ans;
int map[101][101];
int street[101];
bool IsUsed[101];

//start부터 start+l칸까지 경사를 만들 수 있는지 확인
bool IsMakeRmap(int start)
{
	//cout << start << '\n';
	for (int i = start; i < start + l; i++) {
		//범위 밖이거나, 이미 경사로가 있다면
		if (i < 0 || i >= n || IsUsed[i])
			return false;
		//높이가 다르다면
		if (street[start] != street[i])
			return false;
	}

	//경사로 표시
	for (int i = start; i < start + l; i++) {
		IsUsed[i] = true;
	}
	return true;
}

bool IsWalk(int startX, int startY, int endX, int endY)
{
	int idx = 0;
	for (int i = startX; i <= endX; i++) {
		for (int j = startY; j <= endY; j++) {
			street[idx] = map[i][j];
			IsUsed[idx++] = false;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		int next = i + 1;
		if (abs(street[i] - street[next]) > 1) {
			return false;
		}

		//if (next > n) continue;
		//다음 칸이 한 칸 낮으면
		if (street[i] == street[next] + 1) {
			if (!IsMakeRmap(next)) {
				return false;
			}
			//경사 마지막으로 이동 (for 문의 i++ 연산 고려)
			i = next + (l - 2);
		}
		//다음 칸이 한 칸 높으면
		else if (street[i] + 1 == street[next]) {
			if (!IsMakeRmap(i - (l - 1)))
				return false;
		}

	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < n; i++) {
		//row 확인
		if (IsWalk(i, 0, i, n - 1)) 
			ans++;
		//column 확인
		if (IsWalk(0, i, n - 1, i)) 
			ans++;
	}
	cout << ans;
	return 0;
}
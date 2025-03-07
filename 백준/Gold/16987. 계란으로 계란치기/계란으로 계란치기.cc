#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
int weight[8];
int durability[8];
bool isBroken[8];
int ans;

//손에 든 계란 말고 모두 깨진 경우
bool flag(int start)
{
	for (int i = 0; i < n; i++) {
		if(i==start) continue;
		if (!isBroken[i])
			return false;
	}
	return true;
}

//손에 쥐고 있는 계란 및 깨진 계란의 개수를 인자로 받는다.
void func(int start, int cnt)
{
	if (start == n || flag(start)) {
		if (cnt > ans)
			ans = cnt;
		return;
	}
	else {

		if (isBroken[start]) {
			func(start + 1, cnt);
		}
		else {
			//내리 칠 계란 순회
			for (int i = 0; i < n; i++) {
				//손에 쥐고 있는 계란이거나 내리칠 계란이 깨진 계란이면 continue
				if (i == start || isBroken[i] || isBroken[start])
					continue;

				durability[start] -= weight[i];
				if (!isBroken[start] && durability[start] <= 0) {
					isBroken[start] = true;
					cnt++;
				}
				durability[i] -= weight[start];
				if (!isBroken[i] && durability[i] <= 0) {
					isBroken[i] = true;
					cnt++;
				}
				//다음 계란 들기
				func(start + 1, cnt);

				durability[start] += weight[i];
				if (isBroken[start] && durability[start] > 0) {
					isBroken[start] = false;
					cnt--;
				}
				durability[i] += weight[start];
				if (isBroken[i] && durability[i] > 0) {
					isBroken[i] = false;
					cnt--;
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> durability[i] >> weight[i];

	func(0, 0);
	cout << ans;

	return 0;
}
#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int k, ans;
deque<char> gear[4];
bool isRotate[4];

void Rotate(int gearNum, int dir)
{
	isRotate[gearNum] = true;

	//회전하기 전 상태 저장
	char gearCpy[8];
	for (int i = 0; i < 8; i++)
		gearCpy[i] = gear[gearNum][i];

	//반시계방향 회전
	if (dir == -1) {
		gear[gearNum].push_back(gear[gearNum].front());
		gear[gearNum].pop_front();
	}
	//시계방향 회전
	else if(dir==1){
		gear[gearNum].push_front(gear[gearNum].back());
		gear[gearNum].pop_back();
	}

	for (int i = gearNum - 1; i <= gearNum + 1; i++) {
		//범위를 벗어남 또는 이미 회전한 톱니바퀴
		if (i < 0 || i >= 4 || isRotate[i])
			continue;

		if (i == gearNum - 1 && gear[i][2] != gearCpy[6]) {
			Rotate(i, dir * -1);
		}
		else if (i == gearNum + 1 && gearCpy[2] != gear[i][6]) {
			Rotate(i, dir * -1);
		}
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char num;
			cin >> num;
			gear[i].push_back(num);
		}
	}

	cin >> k;
	while (k--) {
		int gearNum, dir;
		cin >> gearNum >> dir;

		for (int i = 0; i < 4; i++)
			isRotate[i] = false;
		Rotate(gearNum - 1, dir);
	}

	//점수 확인
	for (int i = 0; i < 4; i++) {
		if (gear[i].front() == '1') {
			ans += pow(2, i);
		}
	}
	cout << ans;
	return 0;
}
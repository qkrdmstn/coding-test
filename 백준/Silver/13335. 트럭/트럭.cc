#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, w, l;
int weightSum, t;
queue<int> truck;
deque<int> bridge;

//다리가 비어있는지 확인
bool IsEmpty()
{
	for (int i = 0; i < w; i++) {
		if (bridge[i] != 0) {
			return false;
		}
	}
	return true;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		truck.push(weight);
	}

	for (int i = 0; i < w; i++) {
		bridge.push_back(0);
	}

	while (true) {
		//다리의 맨 앞 트럭 내보내기
		weightSum -= bridge.front();
		bridge.pop_front();

		//무게 초과 시, 0 채우기
		if (truck.empty() || weightSum + truck.front() > l) {
			bridge.push_back(0);
		}
		//트럭 진입
		else {
			weightSum += truck.front();
			bridge.push_back(truck.front());
			truck.pop();
		}
		t++;
		if (IsEmpty())
			break;
	}

	cout << t;
	return 0;
}
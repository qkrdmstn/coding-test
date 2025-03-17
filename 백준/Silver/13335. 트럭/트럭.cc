#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, w, l;
int weightSum, t;
queue<int> truck;
deque<int> bridge;

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
		
		bool isEnd = true;
		//다리가 비어있다면 End
		for (int i = 0; i < w; i++) {
			if (bridge[i] != 0) {
				isEnd = false;
				break;
			}
		}
		t++;

		if (isEnd)
			break;
	}

	cout << t;
	return 0;
}
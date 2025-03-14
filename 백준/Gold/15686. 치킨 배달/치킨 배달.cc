#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans = 10000000000;
int map[51][51];
vector<pair<int, int>> chickenPos;
vector<pair<int, int>> housePos;
vector<pair<int, int>> selectedChicken;

int ChickenDist(pair<int, int> pos1, pair<int, int> pos2)
{
	return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

int CalcCityChickenDist()
{
	int cityDist = 0;
	for (int i = 0; i < housePos.size(); i++) {
		int minDist = 1000;
		for (int j = 0; j < selectedChicken.size(); j++) {
			int dist = ChickenDist(housePos[i], selectedChicken[j]);
			minDist = min(minDist, dist);
		}
		cityDist += minDist;
	}
	return cityDist;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				housePos.push_back({ i,j });
			else if (map[i][j] == 2)
				chickenPos.push_back({ i, j });
		}
	}

	int chickenSelect[14] = {};
	for (int i = chickenPos.size() - m; i < chickenPos.size(); i++) {
		chickenSelect[i] = 1;
	}

	//치킨집 중에서 m개의 치킨집 고르기
	do {
		selectedChicken.clear();
		for (int i = 0; i < chickenPos.size(); i++) {
			if (chickenSelect[i] == 1) {
				selectedChicken.push_back(chickenPos[i]);
			}
		}

		ans = min(ans, CalcCityChickenDist());
	} while (next_permutation(chickenSelect, chickenSelect + chickenPos.size()));

	cout << ans;
	return 0;
}
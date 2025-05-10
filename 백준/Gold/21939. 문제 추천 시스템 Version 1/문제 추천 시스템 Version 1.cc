#include <iostream>
#include <set>
using namespace std;

int probs[100002];
set<int> levels[102]; //난이도 별 문제 저장
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l;
		probs[p] = l;
		levels[l].insert(p);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string com;
		cin >> com;

		if (com == "recommend") {
			int x;
			cin >> x;
			if (x == 1) {
				for (int j = 100; j >= 0; j--) {
					if (levels[j].empty()) continue;
					cout << *(prev(levels[j].end())) << '\n';
					break;
				}
			}
			else {
				for (int j = 0; j <= 100; j++) {
					if (levels[j].empty()) continue;
					cout << *levels[j].begin() << '\n';
					break;
				}
			}
		}
		else if (com == "solved") {
			int p;
			cin >> p;
			levels[probs[p]].erase(p);
		}
		else {
			int p, l;
			cin >> p >> l;
			probs[p] = l;
			levels[l].insert(p);
		}
	}
	return 0;
}
#include <iostream>
#include <set>
#include <tuple>
using namespace std;

int n;
set<int> levels[105];
set<int> algos[105][102];
pair<int, int> probs[100'005]; //{level, algorithm}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l, g;
		cin >> p >> l >> g;

		levels[l].insert(p);
		algos[g][l].insert(p);
		probs[p] = { l, g };
	}

	int m;
	cin >> m;
	while (m--) {
		string query;
		cin >> query;

		if (query == "recommend") {
			int g, x;
			cin >> g >> x;

			if (x == 1) {
				for (int i = 100; i >= 1; i--) {
					if (!algos[g][i].empty()) {
						cout << *prev(algos[g][i].end()) << '\n';
						break;
					}
				}

			}
			else {
				for (int i = 1; i <= 100; i++) {
					if (!algos[g][i].empty()) {
						cout << *algos[g][i].begin() << '\n';
						break;
					}
				}
			}
		}
		else if(query == "recommend2"){
			int x;
			cin >> x;
			if (x == 1) {
				for (int i = 100; i >= 1; i--) {
					if (!levels[i].empty()) {
						cout << *prev(levels[i].end()) << '\n';
						break;
					}
				}
				
			}
			else {
				for (int i = 1; i <= 100; i++) {
					if (!levels[i].empty()) {
						cout << *levels[i].begin() << '\n';
						break;
					}
				}
			}
		}
		else if (query == "recommend3") {
			int x, l;
			bool flag = false;

			cin >> x >> l;
			if (x == 1) {
				for (int i = l; i <= 100; i++) {
					if (!levels[i].empty()) {
						cout << *levels[i].begin() << '\n';
						flag = true;
						break;
					}
				}
	
			}
			else {
				for (int i = l - 1; i >= 0; i--) {
					if (!levels[i].empty()) {
						cout << *prev(levels[i].end()) << '\n';
						flag = true;
						break;
					}
				}
			}
			if (!flag)
				cout << -1 << '\n';
		}
		else if (query == "add") {
			int p, l, g;
			cin >> p >> l >> g;
			levels[l].insert(p);
			algos[g][l].insert(p);
			probs[p] = { l, g };
		}
		else if (query == "solved") {
			int p, l, g;
			cin >> p;
			
			tie(l, g) = probs[p];
			levels[l].erase(p);
			algos[g][l].erase(p);
		}
	}
	return 0;
}
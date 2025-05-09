#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		multiset<int> ms;
		for (int i = 0; i < k; i++) {
			char command; int q;
			cin >> command >> q;
			if (command == 'I')
				ms.insert(q);
			else {
				if (ms.empty()) continue;
				if (q == 1) ms.erase(prev(ms.end()));
				else ms.erase(ms.begin());
			}
		}

		if (ms.empty())
			cout << "EMPTY" << '\n';
		else
			cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
	}
	return 0;
}
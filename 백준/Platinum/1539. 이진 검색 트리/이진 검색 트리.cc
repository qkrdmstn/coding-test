#include <iostream>
#include <set>
using namespace std;

int n;
long long ans;
set<int> s;
int h[250'005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	s.insert(n + 1);
	s.insert(0);

	int p;
	cin >> p;
	p++;
	h[p] = 1;
	s.insert(p);
	ans += h[p];
	n--;

	while (n--) {
		cin >> p; p++;
		auto it = s.lower_bound(p);
		h[p] = max(h[*prev(it)], h[*it]) + 1;
		s.insert(p);

		ans += h[p];
	}
	cout << ans;
	return 0;
}
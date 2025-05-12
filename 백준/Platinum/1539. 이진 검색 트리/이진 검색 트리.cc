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

	int p; cin >> p;
	h[p] = 1; s.insert(p);
	ans += h[p];
	n--;

	while (n--) {
		cin >> p;
		auto it = s.lower_bound(p);

		if (it != s.begin() && it != s.end())
			h[p] = max(h[*prev(it)], h[*it]) + 1;
		else if (it == s.begin())
			h[p] = h[*it] + 1;
		else if (it == s.end())
			h[p] = h[*prev(it)] + 1;
		s.insert(p);

		ans += h[p];
	}
	cout << ans;

	return 0;

	/*
	A의 높이 H[A]는 max(H[A보다 작은 수 중 최댓값], H[A보다 큰 수 중 최소값]) + 1
	로 표현 가능.
	이때, lower_bound를 통해 A보다 작은 수 중 최댓값과 A보다 큰 수 중 최소값을 계산할 수 있는데
	예외 처리가 필요
	1. it가 begin()을 가리켜서 prev가 범위를 벗어나는 경우
	2. it가 end()를 가리켜서 it가 범위를 벗어나는 경우

	따라서, while 내부에 if문을 통해 예외처리를 진행
	set에 0과 n+1 값을 미리 삽입하여 가독성 높은 코드로 최적화 가능
	*/
}
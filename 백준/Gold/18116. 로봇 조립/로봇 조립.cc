#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> p(1'000'005, -1);
vector<int> cnt(1'000'005, 1);

int find(int x)
{
	if (p[x] < 0)
		return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u);
	v = find(v);

	//이미 같은 그룹이면 false;
	if (u == v) return false;

	//랭크가 더 큰 그룹을 u, 작은 그룹을 v로 설정
	if (p[u] > p[v])
		swap(u, v);
	//두 그룹의 랭크가 같다면 병합되는 u 그룹의 랭크를 1 증가
	if (p[u] == p[v])
		p[u]--;

	cnt[u] += cnt[v];
	//작은 그룹의 부모를 큰 그룹에 포함시키기 
	p[v] = u;
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'I') {
			int a, b;
			cin >> a >> b;
			uni(a, b);
		}
		else {
			int c;
			cin >> c;
			cout << cnt[find(c)] << '\n';
		}
	}
	return 0;
}
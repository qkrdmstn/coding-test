#include <iostream>
using namespace std;



int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
		}
		//최소 신장 트리의 간선 개수는 노드의 개수 - 1
		cout << n - 1 << '\n';
	}
	return 0;
}
#include <iostream>
#include <stack>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	stack<pair<int, int>> s; //{높이, 번호}
	s.push({ INF, 0 });
	for (int i = 1; i <= n; i++)
	{
		int h;
		cin >> h;
		while (!s.empty() && s.top().first < h)
		{
			s.pop();
		}
		cout << s.top().second << " ";
		s.push({ h, i });
	}

	return 0;
}
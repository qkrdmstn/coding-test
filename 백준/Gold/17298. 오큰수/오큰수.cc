#include <iostream>
#include <stack>
using namespace std;

int NGE[1000001] = {};
stack<pair<int, int>> s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	s.push({ 1000001, 0 });
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		while (s.top().first < a) {
			NGE[s.top().second] = a;
			s.pop();
		}
		s.push({ a, i });
	}

	while (!s.empty()) {
		NGE[s.top().second] = -1;
		s.pop();
	}

	for (int i = 1; i <= n; i++)
		cout << NGE[i] << " ";
	return 0;
    
    //스택에 순서와 수를 같이 저장하여 pop 연산이 일어날 때
    //pop 연산을 일으키는 수를 해당 NGE 배열 인덱스에 저장하는 방식
}
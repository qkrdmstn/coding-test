#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	stack<int> s;
	string ans;
	int pushNum = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		while (pushNum <= num) { //수열의 현재 num이 오름차순으로 push되는 i보다 작은 동안 계속 push
			s.push(pushNum++);
			ans += "+\n";
		}
		if (s.top() != num) { //stack에서 나올 수 없는 순서로 나오는 경우 수열:[6,3] pushNum[1,2,3,4,5,6...] 6에서 pop되고 다음 push num은 7인데 원하는 수는 3일 경우 말이 안됨
			cout << "NO\n";
			return 0;
		}
		s.pop();
		ans += "-\n";
	}

	cout << ans;
	return 0;
}
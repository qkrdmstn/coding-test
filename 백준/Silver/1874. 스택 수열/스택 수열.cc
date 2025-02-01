#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	stack<int> s;
	vector<int> v; //수열을 저장하는 벡터
	vector<char> ans; //답을 저장하는 벡터

	//수열 저장
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int idx = 0;
	int i = 1;
	bool flag = true;
	while (idx != v.size()) {
		while (!s.empty() && v[idx] == s.top()) { //수열의 현재 idx와 stack의 top이 같으면 pop
			s.pop();
			ans.push_back('-');
			idx++;
		}

		if (i > n)
			break;
		s.push(i);
		ans.push_back('+');
		i++;
	}

	if (idx != v.size())
		cout << "NO";
	else {
		for (auto c : ans)
			cout << c << "\n";
	}
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

string s;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	int tmp = 0;
	int sign = 1;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			ans += sign * tmp;
			if (s[i] == '-')
				sign = -1;
			tmp = 0;
		}
		else {
			tmp *= 10;
			tmp += s[i] - '0';
		}
	}
	ans += sign * tmp;
	cout << ans;

	/*
	식에서 -가 나온 이후로는 뒤의 숫자를 모두 빼기 연산에 참여시킬 수 있음
	ex1) 55 + 100 - (102 + 100 + 1021124 + ...)
	ex2) 55 + 100 - (102 + 1024 + 120412) - (12041 + 12412)
	따라서, 처음에는 식의 부호를 +로 설정한 뒤, 앞자리부터 읽기 때문에
	tmp *= 10을 진행하면서 현재 수를 온전히 tmp에 저장한 뒤 현재 부호에 따라 ans에 계산함
	-가 나온 뒤로는 전부 빼면 됨
	*/
	return 0;
}
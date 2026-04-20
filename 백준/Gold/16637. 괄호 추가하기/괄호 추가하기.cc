#include <iostream>
#include <vector>
using namespace std;

int ans = -0x3f3f3f3f;
vector<int> nums;
vector<char> ops;

int clac(int a, char op, int b)
{
	if(op == '+') return a + b;
	else if(op == '-') return a - b;
	else if(op == '*') return a * b;
}

void DFS(int idx, int curVal)
{
	if (idx >= ops.size())
	{
		ans = max(ans, curVal);
		return;
	}

	// 1. 현재 연산자를 괄호 안에 넣지 않는 경우
	int nxtVal = clac(curVal, ops[idx], nums[idx+1]);
	DFS(idx+1, nxtVal);

	if (idx + 1 < ops.size())
	{
		int braketVal = clac(nums[idx + 1], ops[idx + 1], nums[idx + 2]);
		int nxtVal = clac(curVal, ops[idx], braketVal);
		DFS(idx + 2, nxtVal);
	}
}

int main(void)
{
	int n;
	string s;
	cin >> n >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')
			nums.push_back(s[i] - '0');
		else
			ops.push_back(s[i]);
	}

	DFS(0, nums[0]);
	cout << ans;
}
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
void Backtracking(int cnt, long long cur, int target, int& answer)
{
	if (cur >= target)
	{
		if(cur == target)
			answer = min(answer, cnt);
		return;
	}

	Backtracking(cnt+1, cur * 2, target, answer);
	Backtracking(cnt + 1, cur*10 + 1, target,  answer);
}

int main(void)
{
	int answer = INF;
	int a, b;
	cin >> a >> b;
	Backtracking(0, a, b, answer);
	if(answer == INF)
		answer = -2;
	cout << answer + 1;
	return 0;
}
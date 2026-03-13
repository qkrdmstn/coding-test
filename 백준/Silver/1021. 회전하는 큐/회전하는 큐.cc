#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	deque<int> dq;
	for(int i=1; i<=N; i++)
		dq.push_back(i);
	
	int ans = 0;
	while (M--)
	{
		int num;
		cin >> num;

		int idx = 0;
		int size = dq.size();
		for (int i = 0; i < size; i++)
		{
			if (dq[i] == num)
			{
				idx = i + 1;
				break;
			}
		}

		if (idx <= size / 2 + 1)
		{
			//왼쪽으로 회전
			while (dq.front() != num)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
		}
		else
		{
			//오른쪽으로 회전
			while (dq.front() != num)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
		}
		dq.pop_front();
	}
	cout << ans;
	return 0;
}
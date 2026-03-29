#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;


	queue<int> q;
	vector<bool> vis(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		q.push(num);
		vis[num] = true;
	}

	int depth = 0;
	while (!q.empty())
	{
		depth++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int cur = q.front(); q.pop();
			for (int i = 0; i < 20; i++)
			{
				//현재 비밀번호와 안전거리가 1인 비밀번호 생성
				int nxt = cur ^ (1 << i);
				if(nxt > n || vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
		}
	}
	cout << depth - 1;
	return 0;
}
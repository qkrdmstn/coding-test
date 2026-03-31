#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int info[51][9];
int ans = 0;
int Play(vector<int>& order)
{
	int cur = 0;
	int round = 0;
	int score = 0;

	for (int rnd = 0; rnd < n; rnd++)
	{
		queue<int> q;

		int out = 0;
		while (out < 3)
		{
			int player = order[cur];
			int hit = info[rnd][player];
			if (hit == 0)
				out++;
			else
			{
				q.push(order[cur]);
				for (int i = 1; i < hit; i++)
					q.push(-1);
				while (q.size() > 3)
				{
					if (q.front() != -1)
						score++;
					q.pop();
				}
			}
			cur++;
			cur %= 9;
		}
	}
	return score;
}

void DFS(vector<bool>& vis, vector<int>& res)
{
	if (res.size() == 9)
	{
		ans = max(ans, Play(res));
		return;
	}

	//0번 선수는 4번째 고정
	if (res.size() == 3)
	{
		res.push_back(0);
		DFS(vis, res);
		res.pop_back();
		return;
	}
	
	for (int i = 1; i < 9; i++)
	{
		if(vis[i]) continue;
		vis[i] = true;
		res.push_back(i);
		DFS(vis, res);
		res.pop_back();
		vis[i] =  false;
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for(int j=0; j<9; j++)
			cin >> info[i][j];
	}

	vector<bool> vis(9, false);
	vector<int> res;
	vis[0] = true;
	DFS(vis, res);
	cout << ans;
	return 0;
}
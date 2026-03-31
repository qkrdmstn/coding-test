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
		int out = 0;
		int b1 = 0, b2 = 0, b3 = 0;
		while (out < 3)
		{
			int player = order[cur];
			int hit = info[rnd][player];
			if (hit == 0)
				out++;
			else if (hit == 1)
			{
				score += b3;
				b3 = b2;
				b2 = b1;
				b1 = 1;
			}
			else if (hit == 2)
			{
				score += b3 + b2;
				b3 = b1;
				b2 = 1;
				b1 = 0;
			}
			else if (hit == 3)
			{
				score += b3 + b2 + b1;
				b3 = 1;
				b2 = b1 = 0;
			}
			else if (hit == 4)
			{
				score += b3 + b2 + b1 + 1;
				b3 = b2 = b1 = 0;
			}
			cur = (cur + 1) % 9;
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

	for (int i = 0; i < 9; i++)
	{
		if (i == 0 || vis[i]) continue;
		vis[i] = true;
		res.push_back(i);
		DFS(vis, res);
		res.pop_back();
		vis[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> info[i][j];
	}

	vector<bool> vis(9, false);
	vector<int> res;
	DFS(vis, res);
	cout << ans;
	return 0;
}
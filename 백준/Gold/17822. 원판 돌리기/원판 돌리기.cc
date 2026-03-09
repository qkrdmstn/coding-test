#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

void rotate(deque<int>& target, int dir, int k)
{

	while (k--)
	{
		//시계
		if (dir == 0)
		{
			target.push_front(target.back());
			target.pop_back();
		}
		else
		{
			target.push_back(target.front());
			target.pop_front();
		}
	}
}

void remove(vector<deque<int>>& dqVector, int n, int m)
{
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};

	vector<pair<int, int>> removed;
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(dqVector[i][j] == 0) continue;
			sum += dqVector[i][j];
			cnt++;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 1 || nx > n) continue;
				if (ny < 0 || ny >= m) ny = (ny + m) % m;
				if (dqVector[i][j] == dqVector[nx][ny]) removed.push_back({i, j});
				
			}
		}
	}

	if (removed.empty())
	{
		float avg = (float)sum/cnt;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (dqVector[i][j] == 0) continue;
				if(dqVector[i][j] > avg) dqVector[i][j]--;
				else if(dqVector[i][j] < avg) dqVector[i][j]++;
			}
		}
	}
	else
	{
		for (auto r : removed)
			dqVector[r.first][r.second] = 0;
	}
}

int main(void)
{
	int n, m, t;
	cin >> n >> m >> t;

	vector<deque<int>> dqVector(n+1, deque<int>());
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
			dqVector[i].push_back(num);
		}
	}

	while (t--)
	{
		int x, d, k;
		cin >> x >> d >> k;
		for(int i=x; i<=n; i+=x)
			rotate(dqVector[i], d, k);
		remove(dqVector, n, m);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
			ans += dqVector[i][j];
	}
	cout << ans;
	return 0;
}
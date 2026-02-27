#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char op[4] = {'D', 'S', 'L', 'R'};

int operation(char op, int n)
{
	if (op == 'D')
		return 2 * n % 10000;
	else if (op == 'S')
	{
		if(n == 0)
			return 9999;
		return n-1;
	}
	else 
	{
		int d[4];
		for (int i = 3; i >= 0; i--)
		{
			d[i] = n%10;
			n/=10;
		}
		if (op == 'L')
			return ((d[1] * 10 + d[2]) * 10 + d[3]) * 10 + d[0];
		else if (op == 'R')
			return ((d[3] * 10 + d[0]) * 10 + d[1]) * 10 + d[2];
	}
}
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		queue<int> q;
		vector<pair<char, int>> pre(10000);
		vector<int> dist(10000, -1);

		q.push(a);
		dist[a] = 0;
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nxt = operation(op[i], cur);
				if(dist[nxt] >= 0) continue;
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
				pre[nxt] = {op[i], cur};
			}
		}

		vector<char> path;
		int cur = b;
		while (cur != a) {
			path.push_back(pre[cur].first);
			cur = pre[cur].second;
		}
		reverse(path.begin(), path.end());
		for(auto p: path)
			cout << p;
		cout << "\n";
	}
	return 0;
}
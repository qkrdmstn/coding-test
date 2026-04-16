#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
vector<string> targets;

int check(vector<bool>& used)
{
	int res = 0;
	for (string& target : targets)
	{
		bool isPossible = true;
		for (int i = 0; i < target.length(); i++)
		{
			int idx = target[i] - 'a';
			if (!used[idx])
			{
				isPossible = false;
				break;
			}
		}
		if(isPossible) res++;
	}
	return res;
}

void DFS(int st, int cnt, vector<bool>& used, int& ans)
{
	if (cnt == k)
	{
		ans = max(ans, check(used));
		return ;
	}

	for (int i = st; i < 26; i++)
	{
		if(used[i]) continue;
		used[i] = true;
		DFS(i+1, cnt + 1, used, ans);
		used[i] = false;
	}
}

int main(void)
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		targets.push_back(s);
	}

	string fixed = "antic";
	vector<bool> used(26, false);
	for (int i = 0; i < 5; i++)
	{
		int idx = fixed[i] - 'a';
		used[idx] = true;
	}
	k -= 5;
	if (k < 0)
	{
		cout << 0;
		return 0;
	}

	int ans = 0;
	DFS(0, 0, used, ans);
	cout << ans;
	return 0;
}
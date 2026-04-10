#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, k;
vector<bool> used(26, false);
vector<string> s(52);

int Check()
{
	int cnt =0;
	for (int i=0; i<n; i++)
	{
		string word = s[i];
		int len = word.length();
		bool possible = true;
		for (int j = 0; j < len; j++)
		{
			int idx = word[j] - 'a';
			if(!used[idx])
			{
				possible = false;
				break;
			}
		}
		if(possible) cnt++;
	}
	return cnt;
}

void DFS(int st, int cnt, int &ans)
{

	if (cnt == k)
	{
		ans = max(ans, Check());
		return;
	}

	for (int i = st; i < 26; i++)
	{
		if(used[i]) continue;
		used[i] = true;
		DFS(i + 1, cnt + 1, ans);
		used[i] = false;
	}
}

int main(void)
{
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> s[i];

	if (k < 5)
	{
		cout << 0;
		return 0;
	}

	int ans = 0;
	string fixed = "antic";
	for (int i = 0; i < fixed.length(); i++)
	{
		used[fixed[i] - 'a'] = true;
	}

	DFS(0, 5, ans);

	cout << ans;
	return 0;
}
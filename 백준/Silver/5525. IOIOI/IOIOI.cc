#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(void)
{
	int n, m;
	string str;
	cin >> n >> m >> str;

	int len = 2*n + 1;
	int ans = 0;
	for (int st = 0; st <= m - len; st++)
	{
		if(str[st] == 'O') continue;
		int ed = st;
		while (str[ed] != str[ed + 1])
		{
			ed++;
			if(ed-st+1 == len) break;
		}
		if (ed - st + 1 == len)
		{
			ans++;
			//st = ed - 1;
		}
	}
	cout << ans;
	return 0;
}
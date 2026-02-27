#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(void)
{
	int n, m, ans = 0;
	string str;
	cin >> n >> m >> str;

	for (int s = 0; s < m; s++)
	{
		if (str[s] == 'O') continue;
		int cnt = 0;
		while (s + 2 < m && str[s + 1] == 'O' && str[s + 2] == 'I')
		{
			s+=2;
			cnt++;
			if(cnt >= n)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
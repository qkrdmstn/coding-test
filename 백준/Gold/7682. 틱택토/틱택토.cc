#include <iostream>
#include <string>
using namespace std;

bool Check(string s)
{
	int xCnt = 0, oCnt = 0;
	bool xWin = false, oWin = false;

	for (int i = 0; i < 9; i++)
	{
		if (s[i] == 'X') xCnt++;
		else if (s[i] == 'O') oCnt++;
	}
	if (xCnt != oCnt && xCnt != oCnt + 1) return false;

	if (s[0] == s[4] && s[4] == s[8])
	{
		if (s[0] == 'X') xWin = true;
		else if (s[0] == 'O') oWin = true;
	}
	if (s[2] == s[4] && s[4] == s[6])
	{
		if (s[2] == 'X') xWin = true;
		else if (s[2] == 'O') oWin = true;
	}

	if (s[0] == s[1] && s[1] == s[2])
	{
		if (s[0] == 'X') xWin = true;
		else if (s[0] == 'O') oWin = true;
	}
	if (s[3] == s[4] && s[4] == s[5])
	{
		if (s[3] == 'X') xWin = true;
		else if (s[3] == 'O') oWin = true;
	}
	if (s[6] == s[7] && s[7] == s[8])
	{
		if (s[6] == 'X') xWin = true;
		else if (s[6] == 'O') oWin = true;
	}

	if (s[0] == s[3] && s[3] == s[6])
	{
		if (s[0] == 'X') xWin = true;
		else if (s[0] == 'O') oWin = true;
	}
	if (s[1] == s[4] && s[4] == s[7])
	{
		if (s[1] == 'X') xWin = true;
		else if (s[1] == 'O') oWin = true;
	}
	if (s[2] == s[5] && s[5] == s[8])
	{
		if (s[2] == 'X') xWin = true;
		else if (s[2] == 'O') oWin = true;
	}

	if (xWin && oWin) return false;
	if (!xWin && !oWin && xCnt + oCnt != 9) return false;
	if (xWin && xCnt != oCnt + 1) return false;
	if (oWin && xCnt != oCnt) return false;

	return true;
}

int main(void)
{
	while (true)
	{
		string s;
		cin >> s;
		if (s == "end") break;

		if (Check(s)) cout << "valid\n";
		else cout << "invalid\n";
	}
	return 0;
}
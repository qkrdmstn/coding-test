#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Check(string a)
{
	bool xWin = false, oWin = false;
	int xCnt = 0, oCnt = 0;

	for (int i = 0; i < 9; i++)
	{
		if(a[i] == 'X') xCnt++;
		else if(a[i] == 'O') oCnt++;
	}
	if(oCnt > xCnt) return false;

	//가로
	if (a[0] == a[1] && a[1] == a[2])
	{
		if(a[0] == 'X') xWin = true;
		else if(a[0] == 'O') oWin = true;
	}
	if (a[3] == a[4] && a[4] == a[5])
	{
		if (a[3] == 'X') xWin = true;
		else if (a[3] == 'O') oWin = true;
	}
	if	(a[6] == a[7] && a[7] == a[8])
	{
		if (a[6] == 'X') xWin = true;
		else if (a[6] == 'O') oWin = true;
	}

	//세로
	if(a[0] == a[3] && a[3] == a[6])
	{
		if (a[0] == 'X') xWin = true;
		else if (a[0] == 'O') oWin = true;
	}
	if	(a[1] == a[4] && a[4] == a[7]) 
	{
		if (a[1] == 'X') xWin = true;
		else if (a[1] == 'O') oWin = true;
	}
	if	(a[2] == a[5] && a[5] == a[8])
	{
		if (a[2] == 'X') xWin = true;
		else if (a[2] == 'O') oWin = true;
	}

	//대각선
	if (a[0] == a[4] && a[4] == a[8])
	{
		if (a[0] == 'X') xWin = true;
		else if (a[0] == 'O') oWin = true;
	}
	if (a[2] == a[4] && a[4] == a[6])
	{
		if (a[2] == 'X') xWin = true;
		else if (a[2] == 'O') oWin = true;
	}

	if(xWin && oWin) return false;
	if(xWin && xCnt != oCnt + 1) return false;
	if(oWin && oCnt != xCnt) return false;
	if(!xWin && !oWin && xCnt + oCnt != 9) return false;
	return true;
}

int main(void)
{

	string s;
	while (true)
	{
		cin >> s;
		if(s=="end") break;
		if(Check(s)) cout << "valid\n";
		else cout << "invalid\n";
	}
	return 0;
}
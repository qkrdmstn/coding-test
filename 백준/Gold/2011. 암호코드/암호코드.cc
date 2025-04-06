#include <iostream>
#include <string>
using namespace std;

string str;
int a[5005];
int d[5005];
int mod = 1000000;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> str;

	int len = str.length();
	for (int i = 1; i <= len; i++)
		a[i] = str[i - 1] - '0';
	d[0] = 1;

	for (int i = 1; i <= len; i++) {
		if (a[i] > 0) d[i] = (d[i] + d[i - 1]) % mod;
		int x = a[i - 1] * 10 + a[i];
		if (x >= 10 && x <= 26) d[i] = (d[i] + d[i - 2]) % mod;
	}
	cout << d[len];

	/*
	d[i] = 앞에서 i번째 자리까지의 수를 고려해서 나올 수 있는 해석의 가짓수
	가장 뒤의 두 자리가 26보다 크면 현재 d[i-1]의 가짓수가 가능
	26보다 작거나 같으면 현재 d[i-1]의 가짓수 더하기 
	뒤의 두자리를 묶은 + d[i-2] 가짓수가 가능
 	*/
	return 0;
}
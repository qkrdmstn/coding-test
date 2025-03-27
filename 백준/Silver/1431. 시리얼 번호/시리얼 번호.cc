#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string arr[51];

int DigitSum(string a)
{
	int sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9')
			sum += a[i] - '0';
	}
	return sum;
}
bool Compare(string a, string b)
{
	//길이 비교
	if (a.length() < b.length())
		return true;
	else if (b.length() < a.length())
		return false;
	else {
		//자릿수 합 비교
		int digitSumA = DigitSum(a);
		int digitSumB = DigitSum(b);
		if (digitSumA < digitSumB)
			return true;
		else if (digitSumB < digitSumA)
			return false;
		//사전 순 비교
		else {
			return a < b;
		}
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, Compare);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
	return 0;
}
#include<iostream>
using namespace std;

int main()
{
	char a[101];
	int n, sum = 0;

	cin >> n >> a;
	for (int i = 0; i < n; i++)
	{
		sum += (int(a[i]) - 48); //아스키코드에서 0~9 = 48~57
	}
	cout << sum;
	
	return 0;
}
#include <iostream>
using namespace std;

int n;
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	if (n % 2 == 0)
		cout << "CY";
	else
		cout << "SK";
	return 0;
}
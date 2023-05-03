#include<iostream>
using namespace std;

int main(void)
{
	int h, m, t;
	cin >> h >> m;
	cin >> t;

	int x;
	x = h + ((m + t) / 60);

	if ((m + t) > 59)
	{
		if (x > 23)
			cout << x % 24 << " " << (m + t) % 60;
		else
			cout <<  x << " " << (m + t) % 60;
	}
	else
		cout << h << " " << m + t;

	return 0;
}
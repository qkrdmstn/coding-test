#include <iostream>
using namespace std;

int main(void)
{
	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;

		string ans = "wrong";
		if(a*a + b*b == c*c)
			ans = "right";
		if(a*a + c*c == b*b)
			ans = "right";
		if(b*b + c*c == a*a)
			ans = "right";

		cout << ans << '\n';
	}
	return 0;
}
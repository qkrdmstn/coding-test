#include<iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << a + b <<"\n";
	}
}
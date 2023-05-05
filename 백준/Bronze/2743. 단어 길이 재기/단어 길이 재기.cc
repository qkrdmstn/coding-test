#include<iostream>
using namespace std;

int main(void)
{
	char a[101] = { NULL };
	cin >> a;

	int i = 0;
	while (a[i] != NULL)
	{
		i++;
	}
	cout << i ;
	return 0;
}
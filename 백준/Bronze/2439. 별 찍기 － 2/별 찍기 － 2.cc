#include<iostream>
using namespace std;

int main()
{	
	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			cout << " ";
		}

		for (int x = 1; x <= i; x++)
		{
			cout << "*";
		}
		
		cout << endl;
	}
}
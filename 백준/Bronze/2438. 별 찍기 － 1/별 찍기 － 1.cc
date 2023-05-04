#include <iostream>
using namespace std;

int main()
{
	int N,i;
	cin >> N;

	for (i=1; i <= N; i++)
	{	
		for (int x = 1; x <= i; x++) {
			cout << "*";
		}
		cout << endl;
	}

}

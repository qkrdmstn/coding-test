#include<iostream>
using namespace std;


int main(void)
{
	int a, count = 0, b[10] = { -1 };
	bool same;

	for (int i = 0; i < 10; i++)
	{

		cin >> a;
		b[i] = a % 42;
		
	}

	for (int i = 0; i < 10; i++)
	{
		same = false;
		for (int j = i+1; j < 10; j++)
		{
			if (b[i] == b[j])
				same = true;

		}
		if (!same)
			count++;
	}
	
	cout << count;
}

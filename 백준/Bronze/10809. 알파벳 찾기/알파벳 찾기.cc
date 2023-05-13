#include<iostream>
using namespace std;

int main()
{
	char a[101];
	int b[26] = { 0 };
	cin >> a;

	for (int i = 0; i < 26; i++)
	{
		b[i] = -1; //배열 초기화
	}

	int j = 0;
	while (a[j] != '\0')
	{
		if(b[(int)(a[j]) - 97] == -1)
			b[(int)(a[j]) - 97] = j;
		j++;
	}


	for (int i = 0; i < 26; i++)
	{
		if (i == 26)
		{
			cout << b[i];
			continue;
		}

		cout << b[i] << " ";	
	}
	return 0;
}
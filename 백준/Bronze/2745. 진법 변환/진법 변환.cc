#include<iostream>
#include<string>
using namespace std;

int pow(int a, int b);

int main()
{
	string n;
	int b, i = 0, s = 0;
	cin >> n >> b;

	while (n[i] != '\0')
	{
		if (n[i] >= 65) //A~Z
		{
			s += (n[i] - 55) * pow(b, (n.length() - i - 1));
		}
		else if (n[i] >= 48) //0~9
		{
			s += (n[i] - 48) * pow(b, (n.length() - i - 1));
		}
		i++;
	}
	cout << s;

	return 0;
}

int pow(int a, int b)
{
	int s = a;
	for (int i = 0; i < b-1; i++)
		a = a * s;
	if (b == 0)
		a = 1;
	return a;
}

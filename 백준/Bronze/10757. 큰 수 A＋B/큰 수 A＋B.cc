#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int lenA = a.length(), lenB = b.length();
	
	//자릿수가 더 작은 수가 b
	if (lenA < lenB)
	{
		swap(a, b);
		lenA = a.length(); 
		lenB = b.length();
	}

	//길이가 다른 경우
	if (lenA != lenB)
	{
		for (int i = 0; i < lenA - lenB; i++)
			b = "0" + b;
	}
	
	bool carry = false;
	int x, y, digit;
	string result = "\0";
	for (int i = lenA - 1; i >= 0; i--)
	{
		x = a[i] - '0';
		y = b[i] - '0';
		digit = x + y;
		if (carry)
			digit++;

		if (digit > 9)//자리수 올림
		{
			carry = true;
			digit %= 10;
		}
		else
			carry = false;

		result += digit + '0';
	}
	
	if (carry)
		result += "1";

	for (int i = result.length() - 1; i >= 0; i--)
		cout << result[i];

}
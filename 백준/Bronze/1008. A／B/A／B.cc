#include<iostream>

using namespace std;

int main(void)
{

	double a, b;
	cin >> a >> b;
	
	cout.precision(10); //전체 자릿수 고정
	cout.fixed; //자릿수를 소수점 아래부터 세도록

	cout << a / b;

	return 0;
}
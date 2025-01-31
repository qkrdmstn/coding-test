#include <string>
#include <list>
#include <iostream>
using namespace std;

list<char> charList = {};
list<char>::iterator iter;

void OrderL()
{
	if(iter != charList.begin())
		iter--;
}

void OrderD()
{
	if(iter != charList.end())
		iter++;
}

void OrderB()
{
	if (iter != charList.begin()) {
		iter--;
		iter = charList.erase(iter);
	}
}

void OrderP()
{
	char character;
	cin >> character;
	charList.insert(iter, character);
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	//문자열 리스트로 변환
	for (int i = 0; i < str.length(); i++)
		charList.push_back(str[i]);
	iter = charList.end();

	//명령 입력
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		char order;
		cin >> order;

		if (order == 'L')
			OrderL();
		else if (order == 'D')
			OrderD();
		else if (order == 'B')
			OrderB();
		else if (order == 'P')
			OrderP();
	}

	for (auto a : charList)
		cout << a;
	return 0;
}
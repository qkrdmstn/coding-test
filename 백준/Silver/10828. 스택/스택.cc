#include <iostream>
#include <string>
using namespace std;

int stack[100005] = {};
int pos = 0;

void top()
{
	if (pos == 0)
		cout << "-1\n";
	else
		cout << stack[pos - 1] << "\n";
}

void push()
{
	int num;
	cin >> num;

	stack[pos] = num;
	pos++;
}

void pop()
{
	top();
	pos--;
	if (pos < 0)
		pos = 0;
}

void  size()
{
	cout << pos << "\n";
}

void empty()
{
	if (pos == 0)
		cout << "1\n";
	else
		cout << "0\n";
}
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push")
			push();
		else if (str == "pop")
			pop();
		else if (str == "size")
			size();
		else if (str == "empty")
			empty();
		else if (str == "top")
			top();
	}
	return 0;
}
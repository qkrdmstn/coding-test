#include <iostream>
using namespace std;

void result()
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int result;
		cin >> result;
		if (result == 0)
			cnt++;
	}

	if (cnt == 0)
		cout << "E\n";
	else if (cnt == 1)
		cout << "A\n";
	else if (cnt == 2)
		cout << "B\n";
	else if (cnt == 3)
		cout << "C\n";
	else if (cnt == 4)
		cout << "D\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 3; i++)
		result();

	return 0;
}
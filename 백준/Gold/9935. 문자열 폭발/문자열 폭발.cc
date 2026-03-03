#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s, target;
	cin >> s >> target;
	int targetLen = target.length();

	string result = "";
	for (int i = 0; i < s.length(); i++)
	{
		result.push_back(s[i]);

		if (result.length() >= targetLen)
		{
			bool isSame = true;
			for (int j = 0; j < targetLen; j++)
			{
				int idx = result.length() - targetLen + j;
				if (result[idx] != target[j])
				{
					isSame = false;
					break;
				}
			}

			if (isSame)
			{
				for (int j = 0; j < targetLen; j++)
					result.pop_back();
			}
		}
	}

	if(result.length() == 0)
		cout << "FRULA";
	else
		cout << result;
	return 0;
}
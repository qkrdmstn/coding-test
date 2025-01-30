#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int answer[7];
	int options[9];

	//아홉 난쟁이 키 입력
	for (int i = 0; i < 9; i++)
		cin >> options[i];

	//일곱 난쟁이 찾기
	int total = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			total = 0;
			int idx = 0;
			for (int k = 0; k < 9; k++)
			{
				if (k == i || k == j)
					continue;
				answer[idx] = options[k];
				total += answer[idx];
				idx++;
			}
			if (total == 100)
				break;
		}
		if (total == 100)
			break;
	}

	//일곱 난쟁이 키 오름차순 정렬
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6 - i; j++)
		{
			if (answer[j] > answer[j + 1])
			{
				int temp = answer[j];
				answer[j] = answer[j + 1];
				answer[j + 1] = temp;
			}
		}
	}
	
	//출력
	for (int i = 0; i < 7; i++)
		cout << answer[i] << "\n";
	return 0;
}
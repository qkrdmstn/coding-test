#include <iostream>
#include <list>
using namespace std;


int main(void)
{
	int n, k;
	cin >> n >> k;

	list<int> numList = {};
	for (int i = 1; i <= n; i++) {
		numList.push_back(i);
	}

	cout << "<";
	list<int>::iterator iter = numList.begin();
	while (!numList.empty()) {
		//길이를 활용하여 % 연산으로, 시계/반시계로 돌아가는 방식으로 최적화 가능
		for (int i = 0; i < k - 1; i++) {
			if(iter != numList.end())
				iter++;
			if (iter == numList.end())
				iter = numList.begin();
		}
		int num = *iter;
		iter = numList.erase(iter);
		if (iter == numList.end())
			iter = numList.begin();

		if (!numList.empty())
			cout << num << ", ";
		else
			cout << num;
	}
	cout << ">";
	return 0;
}
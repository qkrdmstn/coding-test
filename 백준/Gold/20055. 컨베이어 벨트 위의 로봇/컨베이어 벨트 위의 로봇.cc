#include <iostream>
#include <deque>
using namespace std;

void Rotate(deque<pair<int, bool>>& belt, int n)
{
	belt.push_front(belt.back());
	belt.pop_back();
	if(belt[n - 1].second) belt[n - 1].second = false;
}

void Move(deque<pair<int, bool>>& belt, int n)
{
	for (int i = 2 * n - 2; i >= 0; i--)
	{
		if(!belt[i].second) continue;

		if (belt[i + 1].first > 0 && !belt[i + 1].second)
		{
			belt[i].second = false;
			belt[i + 1].first--;
			belt[i + 1].second = true;
		}
		if (belt[n - 1].second) belt[n - 1].second = false;
	}
}

void Up(deque<pair<int, bool>>& belt)
{
	if (belt[0].first > 0)
	{
		belt[0].first--;
		belt[0].second = true;
	}
}

int Count(deque<pair<int, bool>>& belt, int n)
{
	int cnt = 0;
	for (int i = 0; i<2*n; i++)
	{
		if (belt[i].first == 0) cnt++;
	}
	return cnt;
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	deque<pair<int, bool>> belt;
	for (int i = 0; i < 2*n; i++)
	{
		int a;
		cin >> a;
		belt.push_back({a, false});
	}

	int step = 0;
	while (true)
	{
		step++;
		Rotate(belt, n);
		Move(belt, n);
		Up(belt);
		if(Count(belt, n)>=k)break;
	}
	cout << step;
	return 0;
}
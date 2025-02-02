#include <iostream>
#include <string>
using namespace std;

const int MX = 100005;
int dq[2 * MX + 1];
int head = MX, tail = MX;

int size()
{
	return tail - head;
}

bool empty()
{
	if (head == tail)
		return true;
	else
		return false;
}

void push_front(int num)
{
	dq[head - 1] = num;
	head--;
}

void push_back(int num)
{
	dq[tail] = num;
	tail++;
}

void pop_front()
{
	head++;
}

void pop_back()
{
	tail--;
}

int front()
{
	return dq[head];
}

int back()
{
	return dq[tail - 1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;

		if (str == "push_front") {
			int x;
			cin >> x;
			push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			push_back(x);
		}
		else if (str == "pop_front") {
			if (!empty()) {
				cout << front() << "\n";
				pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (str == "pop_back") {
			if (!empty()) {
				cout << back() << "\n";
				pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size") {
			cout << size() << "\n";
		}
		else if (str == "empty") {
			cout << empty() << "\n";
		}
		else if (str == "front") {
			if (!empty())
				cout << front() << "\n";
			else
				cout << "-1\n";
		}
		else if (str == "back") {
			if (!empty())
				cout << back() << "\n";
			else
				cout << "-1\n";
		}
	}

	return 0;

	//배열을 활용한 deque 방식
}
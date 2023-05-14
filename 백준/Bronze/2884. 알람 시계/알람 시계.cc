#include<iostream>
using namespace std;

int main()
{
	int h = 0, m = 0, b;

	cin >> h >> m;

	m -= 45; 

	if (m < 0){
		m += 60;
		if (h == 0)
			h = 23;
		else
			h--;
	}

	cout << h <<" "<< m << endl;

	return 0;
}
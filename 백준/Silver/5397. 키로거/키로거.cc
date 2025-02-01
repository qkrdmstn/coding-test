#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		//문자열 리스트로 변환
		list<char> password = {};
		list<char>::iterator iter = password.begin();
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '<') {
				if (iter != password.begin()) 
					iter--;
			}
			else if (str[j] == '>') {
				if (iter != password.end()) 
					iter++;
			} 
			else if (str[j] == '-') {
				if (iter != password.begin()) {
					iter--;
					iter = password.erase(iter);
				}
			}
			else
				password.insert(iter, str[j]);
		}

		//결과 출력
		for (list<char>::iterator iter1 = password.begin(); iter1 != password.end(); iter1++)
			cout << *iter1;
		cout << "\n";
	}

	return 0;
}
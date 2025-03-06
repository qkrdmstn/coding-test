#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char alphabet[15];
char password[15];
bool isUsed[15];
int cntAlphabet[2]; //0: 모음, 1: 자음

void func(int cnt, int start)
{
	if (cnt == l) {
		//모음 자음 개수 확인
		if (cntAlphabet[0] >= 1 && cntAlphabet[1] >= 2) {
			for (int i = 0; i < cnt; i++)
				cout << password[i];
			cout << '\n';
		}
		return;
	}
	else {
		for (int i = start; i < c; i++) {
			if (isUsed[i])
				continue;
			isUsed[i] = true;
			if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u')
				cntAlphabet[0]++;
			else
				cntAlphabet[1]++;
			password[cnt] = alphabet[i];
			func(cnt + 1, i + 1);
			isUsed[i] = false;
			if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u')
				cntAlphabet[0]--;
			else
				cntAlphabet[1]--;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; i++)
		cin >> alphabet[i];
	sort(alphabet, alphabet + c);

	func(0, 0);
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void Input(vector<int> &number)
{
    for(int i=0; i<5; i++)
        cin >> number[i];
}

void output(int answer)
{
    cout << answer;
}

int main(void)
{
    vector<int> number(5);
    Input(number);

    int answer = 0;
    for(auto n: number)
        answer += n*n;
    answer%=10;
    cout << answer;
}
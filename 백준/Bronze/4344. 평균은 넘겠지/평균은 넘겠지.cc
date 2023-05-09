#include<iostream>
using namespace std;

int main()
{
    int c, n, count;
    int  score[1000] = { 0 };
    double sum, mean, ratio = 0;

    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> n;
        sum = 0; //여러번 사용하는 변수 초기화
        count = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> score[j];
            sum += score[j];
        }
        mean = sum / n;

        for (int j = 0; j < n; j++)
        {
            if (score[j] > mean)
                count++;
        }
        ratio = (double)count / n * 100;

        cout << fixed;
        cout.precision(3);
        cout << showpoint << ratio << "%" << endl;
    }

    return 0;
}
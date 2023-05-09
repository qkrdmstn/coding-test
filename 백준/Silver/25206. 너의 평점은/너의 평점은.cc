#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

vector<string> split(string str, char delimeter) //split 함수 구현
{
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, delimeter))
    {
        result.push_back(buffer);
    }

    return result;
}

//1-4 -> 아스키 코드: 49-52
int main()
{
    string a;
    double sum = 0, gradeSum = 0;

    for (int i = 0; i < 20; i++)
    {
        getline(cin, a);
        vector<string> result = split(a, ' ');
        string c = result[1];
        string grade = result[2];

        if (grade[0] != 'P')
        {
            sum += (c[0] - 48);

            if (grade == "A+")
                gradeSum += 4.5 * (c[0] - 48);
            else if (grade == "A0")
                gradeSum += 4.0 * (c[0] - 48);
            else if (grade == "B+")
                gradeSum += 3.5 * (c[0] - 48);
            else if (grade == "B0")
                gradeSum += 3.0 * (c[0] - 48);
            else if (grade == "C+")
                gradeSum += 2.5 * (c[0] - 48);
            else if (grade == "C0")
                gradeSum += 2.0 * (c[0] - 48);
            else if (grade == "D+")
                gradeSum += 1.5 * (c[0] - 48);
            else if (grade == "D0")
                gradeSum += 1.0 * (c[0] - 48);
            else if (grade == "F")
                gradeSum += 0.0;
        }
    }
    cout << fixed;
    cout.precision(6);
    cout << gradeSum / sum;


    return 0;
}
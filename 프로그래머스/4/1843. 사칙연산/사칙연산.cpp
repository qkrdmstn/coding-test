#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int solution(vector<string> arr)
{
    int answer = -1;
    
    //숫자 추출
    vector<int> number;
    for(int i=0; i<arr.size(); i++)
    {
        if(i%2==0)
            number.push_back(stoi(arr[i]));
    }
    
    int num = number.size();
    vector<vector<int>> maxDP(num, vector<int>(num, -INF));
    vector<vector<int>> minDP(num, vector<int>(num, INF));
    
    //길이가 0인 연산
    for(int i=0; i<num; i++)
    {
        maxDP[i][i] = number[i];
        minDP[i][i] = number[i];
    }
    
    for(int diff=1; diff<num; diff++)
    {
        for(int st=0; st<num-diff; st++)
        {
            int ed=st+diff;
            
            // st~ed 사이의 수식 중 중간점 k를 기준으로 좌우로 나눠 최대/최소값을 계산합니다.
            for(int k=st; k<ed; k++)
            {
                int operatorIdx = 2*k+1;
                // 각 연산자에 맞는 최대/최소 값 계산식을 적용합니다.
                if(arr[operatorIdx] == "+")
                {
                    maxDP[st][ed] = max(maxDP[st][k] + maxDP[k+1][ed], maxDP[st][ed]);
                    minDP[st][ed] = min(minDP[st][k] + minDP[k+1][ed], minDP[st][ed]);
                }
                else
                {
                    maxDP[st][ed] = max(maxDP[st][k] - minDP[k+1][ed], maxDP[st][ed]);
                    minDP[st][ed] = min(minDP[st][k] - maxDP[k+1][ed], minDP[st][ed]);
                }
            }
        }
    }
    return maxDP[0][num-1];
}
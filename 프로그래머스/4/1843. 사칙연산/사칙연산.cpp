#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int solution(vector<string> arr)
{
    int answer = -1;
    
    // 숫자를 추출합니다.
    vector<int> numbers;
    for(int i=0; i<(int)arr.size(); i++)
    {
        if(i%2==0) 
            numbers.push_back(stoi(arr[i]));
    }
    
    // 연산자에 따라 최대값 연산 방법이 다르기 때문에, min과 max인 경우 모두 저장합니다.
    int n = numbers.size();
    vector<vector<int>> minDP(n, vector<int>(n, INF));
    vector<vector<int>> maxDP(n, vector<int>(n, -INF));
    
    // 길이가 0인 연산을 수행합니다.
    for(int i=0; i<n; i++)
        minDP[i][i] = maxDP[i][i] = numbers[i];
    
    for(int diff=0; diff<n; diff++)
    {
        for(int st=0; st<n-diff; st++)
        {
            int ed = st+diff;
            
            // st~ed-1 사이에 k번째 수를 지정해 k를 기준으로 앞뒤의 식을 계산해 최대/최소값을 갱신합니다.
            for(int k=st; k<ed; k++)
            {
                // k가 나눈 식의 중간 연산자가 +인 경우와 -인 경우 각각 알맞은 식을 사용해 계산합니다.
                string op = arr[2*k+1];
                if(op == "+")
                {
                    minDP[st][ed] = min(minDP[st][k] + minDP[k+1][ed], minDP[st][ed]);
                    maxDP[st][ed] = max(maxDP[st][k] + maxDP[k+1][ed], maxDP[st][ed]);
                }
                else
                {
                    minDP[st][ed] = min(minDP[st][k] - maxDP[k+1][ed], minDP[st][ed]);
                    maxDP[st][ed] = max(maxDP[st][k] - minDP[k+1][ed], maxDP[st][ed]);
                }
            }
            
        }
    }
    return maxDP[0][n-1];
}
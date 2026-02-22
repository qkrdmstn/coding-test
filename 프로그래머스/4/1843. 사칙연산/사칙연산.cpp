#include <vector>
#include <string>
using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    
    //dp[i][j]: i번째 숫자부터 j번째 숫자까지의 최대/최소값
    int n = arr.size() / 2 + 1; //숫자 개수
    
    //각각 충분히 작은 수와 큰 수로 초기화
    vector<vector<int>> maxDP(n, vector<int>(n, -2e9));
    vector<vector<int>> minDP(n, vector<int>(n, 2e9));
    
    //i번째부터 i번째까지의 최대/최소는 자기 자신
    for(int i=0; i<n; i++)
    {
        int num = stoi(arr[2*i]);
        maxDP[i][i] = minDP[i][i] = num;
    }
    
    //길이 늘려가면서 dp 테이블 계산
    for(int len = 1; len < n; len++)
    {
        for(int i=0; i<n-len; i++)
        {
            int j = i + len; //i~j까지
            //k: i~j 사이에 있는 k번째 수를 선택하여 범위를 나눕니다.
            for(int k=i; k<j; k++)
            {
                //k번째 수에 해당하는 중간 연산자
                string op = arr[2*k + 1];
                if(op == "+")
                {
                    //중간 연산자가 +인 경우 max = max + max, min = min + min
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] + maxDP[k+1][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][k] + minDP[k+1][j]);
                }
                else
                {
                    //중간 연산자가 -인 경우 max = max - min, min = min - max
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] - minDP[k+1][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][k] - maxDP[k+1][j]);
                }
            }
        }
    }
    //0~n-1번째까지 최댓값
    return maxDP[0][n-1];
}
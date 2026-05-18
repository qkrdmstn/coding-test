#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int solution(vector<string> arr)
{
    // 식에서 숫자를 추출한다.
    vector<int> num;
    for(auto& a: arr)
    {
        if(a != "+" && a != "-") num.push_back(stoi(a));
    }
    
    // DP[i][j]: i~j 번째 숫자 구간에서 서로 다른 연산순서의 최댓값 최대/최소 결과값
    int n = num.size();
    vector<vector<int>> maxDP(n, vector<int>(n, -INF));
    vector<vector<int>> minDP(n, vector<int>(n, INF));
    for(int i=0; i<n; i++)
        maxDP[i][i] = minDP[i][i] = num[i]; // diff == 0인 식은 자기 자신이 최대/최소 값이 된다.
    
    for(int diff = 1; diff < n; diff++)
    {
        for(int st = 0; st < n-diff; st++)
        {
            int ed = st + diff;
            // [st,ed] 구간에서 중간 지점 k를 택해 계산을 수행하여 최대/최소값을 택한다.
            for(int k=st; k<ed; k++)
            {
                int opIdx = 2*k + 1;
                // 중간 연산자가 +인 경우, max[st][ed] = max[st][k] + max[k+1][ed] / min[st][ed] = min[st][k] + min[k+1][ed] 으로 성립
                if(arr[opIdx] == "+")
                {
                    maxDP[st][ed] = max(maxDP[st][k] + maxDP[k+1][ed], maxDP[st][ed]);
                    minDP[st][ed] = min(minDP[st][k] + minDP[k+1][ed], minDP[st][ed]);
                }
                // -인 경우, max[st][ed] = max[st][k] - min[k+1][ed] / min[st][ed] = min[st][k] - max[k+1][ed] 이 된다.
                else
                {
                    maxDP[st][ed] = max(maxDP[st][k] - minDP[k+1][ed], maxDP[st][ed]);
                    minDP[st][ed] = min(minDP[st][k] - maxDP[k+1][ed], minDP[st][ed]);
                }
            }
        }
    }

    return maxDP[0][n-1];
}
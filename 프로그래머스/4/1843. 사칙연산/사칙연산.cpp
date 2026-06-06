#include <vector>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;
int solution(vector<string> arr)
{
    int answer = -1;
    
    vector<int> number;
    for(const auto& a: arr)
    {
        if(a != "+" && a != "-")
            number.push_back(stoi(a));
    }
    
    int n = number.size();
    vector<vector<int>> maxDP(n, vector<int>(n, -INF));
    vector<vector<int>> minDP(n, vector<int>(n, INF));
    for(int i=0; i<n; i++)
        maxDP[i][i] = minDP[i][i] = number[i];
    
    for(int len=2; len<=n; len++)
    {
        for(int st=0; st<=n-len; st++)
        {
            int ed = st + len - 1;
            for(int m=st; m<ed; m++)
            {
                string op = arr[2*m+1];
                if(op == "+")
                {
                    maxDP[st][ed] = max(maxDP[st][m] + maxDP[m+1][ed], maxDP[st][ed]);
                    minDP[st][ed] = min(minDP[st][m] + minDP[m+1][ed], minDP[st][ed]);
                }
                else
                {
                    maxDP[st][ed] = max(maxDP[st][m] - minDP[m+1][ed], maxDP[st][ed]);
                    minDP[st][ed] = min(minDP[st][m] - maxDP[m+1][ed], minDP[st][ed]);
                }
            }
        }
    }
    
    return maxDP[0][n-1];
}
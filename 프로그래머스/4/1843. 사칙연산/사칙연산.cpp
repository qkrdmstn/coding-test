#include <vector>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;
int solution(vector<string> arr)
{
    int answer = -1;
    int n = arr.size()/2 + 1;
    vector<vector<int>> minDP(n, vector<int>(n, INF));
    vector<vector<int>> maxDP(n, vector<int>(n, -INF));
    
    for(int i=0; i<n; i++)
        minDP[i][i] = maxDP[i][i] = stoi(arr[2*i]);
    
    for(int len=1; len<n; len++)
    {
        for(int st=0; st < n-len; st++)
        {
            int ed = st + len;
            for(int mid=st; mid<ed; mid++)
            {
                if(arr[2*mid + 1] == "+")
                {
                    minDP[st][ed] = min(minDP[st][ed], minDP[st][mid] + minDP[mid+1][ed]);
                    maxDP[st][ed] = max(maxDP[st][ed], maxDP[st][mid] + maxDP[mid+1][ed]);
                }
                else
                {
                    minDP[st][ed] = min(minDP[st][ed], minDP[st][mid] - maxDP[mid+1][ed]);
                    maxDP[st][ed] = max(maxDP[st][ed], maxDP[st][mid] - minDP[mid+1][ed]);
                }
            }
        }
    }
    return maxDP[0][n-1];
}
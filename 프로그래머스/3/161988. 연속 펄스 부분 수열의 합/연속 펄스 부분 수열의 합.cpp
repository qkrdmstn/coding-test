#include <string>
#include <vector>

using namespace std;
typedef long long ll;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int n = sequence.size();
    
    vector<int> seq1;
    vector<int> seq2;
    for(int i=0; i<n; i++)
    {
        int seq = sequence[i];
        if(i%2 == 0)
        {
            seq1.push_back(seq);
            seq2.push_back(-seq);
        }
        else
        {
            seq1.push_back(-seq);
            seq2.push_back(seq);
        }
    }
    
    vector<ll> dp1(n);
    vector<ll> dp2(n);
    dp1[0] = seq1[0];
    dp2[0] = seq2[0];
    for(int i=1; i<n; i++)
    {
        dp1[i] = max((ll)seq1[i], dp1[i-1] + seq1[i]);
        dp2[i] = max((ll)seq2[i], dp2[i-1] + seq2[i]);
    }
    for(int i=0; i<n; i++)
        answer = max(answer, max(dp1[i], dp2[i]));
    return answer;
}
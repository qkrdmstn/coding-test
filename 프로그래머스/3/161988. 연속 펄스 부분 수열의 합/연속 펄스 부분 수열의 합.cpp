#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    int len = sequence.size();
    vector<int> seq1;
    vector<int> seq2;
    for(int i=0; i<len; i++)
    {
        int s = sequence[i];
        if(i%2==0)
        {
            seq1.push_back(s);
            seq2.push_back(-s);
        }
        else
        {
            seq1.push_back(-s);
            seq2.push_back(s);
        }
    }
    
    vector<long long> dp1(len, 0);
    vector<long long> dp2(len, 0);

    dp1[0] = max(0, seq1[0]);
    dp2[0] = max(0, seq2[0]);
    
    for(int i=1; i<len; i++)
    {
        dp1[i] = max(dp1[i-1] + (long long)seq1[i], (long long)seq1[i]);
        dp2[i] = max(dp2[i-1] + (long long)seq2[i], (long long)seq2[i]);
    }
    
    for(int i=0; i<len; i++)
        answer = max(answer, max(dp1[i], dp2[i]));
    return answer;
}
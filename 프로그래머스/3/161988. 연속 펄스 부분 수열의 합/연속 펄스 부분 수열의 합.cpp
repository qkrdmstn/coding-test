#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    int n = sequence.size();
    vector<int> seq1;
    vector<int> seq2;
    
    int c = 1;
    for(const int& seq: sequence)
    {
        seq1.push_back(seq * c);
        seq2.push_back(seq * -c);
        c *= -1;
    }
    
    vector<long long> dp1(n, 0);
    vector<long long> dp2(n, 0);
    
    dp1[0] = max(0, seq1[0]);
    dp2[0] = max(0, seq2[0]);
    for(int i=1; i<n; i++)
    {
        dp1[i] = max(max(dp1[i-1] + seq1[i], (long long)seq1[i]), (long long)0);
        dp2[i] = max(max(dp2[i-1] + seq2[i], (long long)seq2[i]), (long long)0);
    }
    
    for(int i=0; i<n; i++)
        answer = max(answer, max(dp1[i], dp2[i]));
    return answer;
}
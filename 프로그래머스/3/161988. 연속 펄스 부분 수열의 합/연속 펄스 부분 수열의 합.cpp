#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    vector<int> seq1;
    vector<int> seq2;
    int len = sequence.size();
    
    // 펄스 수열의 두 가지 경우를 곱한 수열을 만들어냅니다.
    int c = 1;
    for(const auto& s: sequence)
    {
        seq1.push_back(s * c);
        seq2.push_back(s * -c);
        c *= -1;
    }
    
    vector<long long> dp1(len, 0);
    vector<long long> dp2(len, 0);
    dp1[0] = max(seq1[0], 0);
    dp2[0] = max(seq2[0], 0);
    
    // 누적합을 포함할지, 현재 원소부터 다시 합을 시작할지 결정하는 DP를 활용합니다.
    for(int i=1; i<len; i++)
    {
        dp1[i] = max(dp1[i-1] + seq1[i], (long long)seq1[i]);
        dp2[i] = max(dp2[i-1] + seq2[i], (long long)seq2[i]);
    }
    
    for(int i=0; i<len; i++)
        answer = max(max(dp1[i], dp2[i]), answer);
    return answer;
}
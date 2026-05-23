#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int n = sequence.size();
    
    // 주어진 수열에 각각의 펄스 수열을 곱합니다.
    vector<int> arr1(n, 0);
    vector<int> arr2(n, 0);
    for(int i=0; i<n; i++)
    {
        if(i%2 == 0)
        {
            arr1[i] = sequence[i];
            arr2[i] = -sequence[i];
        }
        else
        {
            arr1[i] = -sequence[i];
            arr2[i] = sequence[i];
        }
    }
    
    vector<long long> dp1(n, 0);
    vector<long long> dp2(n, 0);
    dp1[0] = arr1[0];
    dp2[0] = arr2[0];
    for(int i=1; i<n; i++)
    {
        dp1[i] = max(dp1[i-1] + arr1[i], (long long)arr1[i]);
        dp2[i] = max(dp2[i-1] + arr2[i], (long long)arr2[i]);
    }
    for(int i=0; i<n; i++)
        answer = max(max(dp1[i], dp2[i]), answer);
    return answer;
}
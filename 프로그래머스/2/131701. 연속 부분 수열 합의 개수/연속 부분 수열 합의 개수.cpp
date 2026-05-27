#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    // 원형 수열의 연결을 표현하기 위해 수열을 복사한다.
    int n = elements.size();
    for(int i=0; i<n; i++)
        elements.push_back(elements[i]);
    
    // 중복 제거를 위해 set 자료구조 사용
    unordered_set<int> s;
    
    // 길이에 따른 각 합들을 set에 저장
    for(int len = 1; len <= n; len++)
    {
        // 첫 윈도우 계산
        int sum = 0;
        for(int i=0; i<len; i++) 
            sum += elements[i];
        s.insert(sum);
        
        // 윈도우 슬라이딩
        for(int st=1; st < n; st++)
        {
            sum += elements[st + len - 1];
            sum -= elements[st-1];
            s.insert(sum);
        }
    }
    return s.size();
}
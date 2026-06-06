#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int INF = 55;

// 주어진 규칙에 맞게 변환이 가능한지 확인하는 함수입니다.
bool IsConvertable(string& cur, string& target)
{
    int len = cur.length();
    int diffCnt = 0;
    for(int i=0; i<len; i++)
    {
        if(cur[i] != target[i]) diffCnt++;
    }
    return diffCnt == 1;
}

// DFS를 활용해 begin -> target 으로 변환하는 경로를 찾습니다.
void FindPath(int depth, string cur, vector<bool>& used, vector<string>& words, string target, int& answer)
{
    // 변환 성공 시, 몇 번 변환했는지 기록하고 현재 경로 탐색을 종료합니다.
    if(cur == target)
    {
        answer = min(depth, answer);
        return;
    }
    
    for(int i=0; i<words.size(); i++)
    {
        // 현재 문자열에서 다음 문자열로 규칙에 의해 변환이 불가능하면 건너뜁니다.
        if(used[i] || !IsConvertable(cur, words[i])) continue;
        used[i] = true;
        FindPath(depth + 1, words[i], used, words, target, answer);
        used[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = INF;
    
    int n = words.size();
    vector<bool> used(n, false);
    FindPath(0, begin, used, words, target, answer);
    
    if(answer == INF) return 0;
    return answer;
}
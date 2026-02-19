#include <string>
#include <vector>

using namespace std;

void DFS(int curSum, int target, int curLen, int maxLen, vector<int>& numbers, int& answer)
{
    if(curLen == maxLen)
    {
        if(curSum == target)
            answer++;
        return;
    }
    DFS(curSum + numbers[curLen], target, curLen + 1, maxLen, numbers, answer);
    DFS(curSum - numbers[curLen], target, curLen + 1, maxLen, numbers, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(0, target, 0, numbers.size(), numbers, answer);
    return answer;
}
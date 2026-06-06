#include <string>
#include <vector>

using namespace std;

void DFS(int depth, int sum, vector<int>& numbers, int target, int& ans)
{
    // 더한 수의 개수가 주어진 배열과 같으면 종료합니다.
    if(depth == numbers.size())
    {
        if(sum == target) ans++;
        return;
    }
    
    // 각 재귀마다 현재 수의 부호를 양수/음수로 설정하여 더합니다.
    int num = numbers[depth];
    DFS(depth + 1, sum + num, numbers, target, ans);
    DFS(depth + 1, sum - num, numbers, target, ans);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(0, 0, numbers, target, answer);
    return answer;
}
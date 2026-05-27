#include <string>
#include <vector>

using namespace std;

typedef long long ll;
int At(ll idx, int n)
{
    // 1차원 인덱스를 2차원 인덱스로 변환 후, 해당 자리에 있는 수를 계산
    return max(idx/n, idx%n) + 1;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(ll cur = left; cur<=right; cur++)
        answer.push_back(At(cur,n));
    return answer;
}
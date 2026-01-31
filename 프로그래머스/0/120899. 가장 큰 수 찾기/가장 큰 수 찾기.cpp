#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    auto a = max_element(array.begin(), array.end());
    answer.push_back(*a);
    answer.push_back((int)(a-array.begin()));
    return answer;
}
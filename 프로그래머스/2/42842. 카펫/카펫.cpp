#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int totalSize = brown + yellow;
    
    for(int i=1; i*i <= yellow; i++)
    {
        if(yellow % i != 0) continue;
        int row = yellow / i;
        int height = i;
        
        if((row + 2) * (height + 2) == totalSize)
        {
            answer.push_back(row + 2);
            answer.push_back(height + 2);
            break;
        } 
        
    }
    return answer;
}
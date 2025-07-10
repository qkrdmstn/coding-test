#include <string>
#include <vector>
#include <queue>
using namespace std;

//2중 반복문으로 찾는 문자 컨테이너 모두 .으로 수정
void Crain(vector<string>& storage, char c)
{
    for(int i=0; i<storage.size(); i++){
        for(int j=0; j<storage[i].size(); j++){
            if(storage[i][j] == c)
                storage[i][j] = '.';
        }
    }    
}

//해당 위치로부터 빈칸으로 이동하여 외부와 만나면 true, 아니면 false
bool bfs(vector<string>& storage, int i, int j)
{
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    queue<pair<int, int>> q;
    bool visit[51][51] = {};
    q.push({i,j});
    visit[i][j] = true;
                
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if(nx<0||nx>=storage.size() || ny < 0 || ny >= storage[0].size())
                return true;
            if(visit[nx][ny]) continue;
            if(storage[nx][ny] != '.') continue;
            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
    return false;
}

void Jigae(vector<string>& storage, char c)
{
    //일치하는 문자를 찾아 bfs 수행
    bool vis[51][51] = {};
    for(int i=0; i<storage.size(); i++){
        for(int j=0; j<storage[i].size(); j++){
            if(storage[i][j] == c){
                vis[i][j] = bfs(storage,i,j);
            }
        }
    }
    
    //외부와 연결된 컨테이너들을 '.'으로 수정
    for(int i=0; i<storage.size(); i++){
        for(int j=0; j<storage[i].size(); j++){
            if(vis[i][j]) storage[i][j] = '.';
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    for(int i=0; i<requests.size(); i++){
        char c = requests[i][0];
        if(requests[i].length() > 1)
            Crain(storage, c);
        else
            Jigae(storage, c);
    }
    
    for(int i=0; i<storage.size(); i++){
        for(int j=0; j<storage[i].size(); j++){
            if(storage[i][j] != '.') answer++;
        }
    }
    return answer;
}
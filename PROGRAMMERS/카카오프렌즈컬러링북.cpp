#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

queue<pair<int,pair<int,int>> > q;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int visited[101][101];
int bfs(int wid, int hgt, int color,vector<vector<int>> picture){
    int MM = 0;
    while(!q.empty()){
        int px = q.front().second.second;
        int py = q.front().second.first;
        int cnt = q.front().first;
        q.pop();
        
        MM++;
        
        for(int dir = 0; dir<4;dir++){
            int nx = px + dx[dir];
            int ny = py + dy[dir];
            if(0<=nx && nx<wid && 0<=ny && ny<hgt){
                if(!visited[ny][nx] && picture[ny][nx]==color){
                    q.push({cnt+1,{ny,nx}});
                    visited[ny][nx]=1;
                }
            }
        }
    }
    return MM; 
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = -1;
    
    memset(visited,0,sizeof(visited));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && picture[i][j]){
                number_of_area++;
                q.push({1,{i,j}});
                visited[i][j]=1;
                max_size_of_one_area = max(max_size_of_one_area,bfs(n,m,picture[i][j],picture));
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
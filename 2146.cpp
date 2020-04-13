#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

// 다리 만들기

typedef pair<int, int> point;

int N;
int island_count;
int map[101][101];
int index_map[101][101];
bool visited[101][101];
int answer = 987654321;

vector <point> maps;

point dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

int getMinDistance(int n) {
    queue<point> que;
    
    memset(visited, false, sizeof(visited));
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++) {
            if(index_map[i][j] == n) {
                visited[i][j] = true;
                que.push({i, j});
            }
        }
    
    int ans = 0;
    
    while(!que.empty()) {
        
        int size = que.size();
        while(size--) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            
            for(int i = 0; i<4; i++) {
                int rr = r + dir[i].first;
                int cc = c + dir[i].second;
                
                if(rr < 0 || rr >= N) continue;
                if(cc < 0 || cc >= N) continue;
                
                if(index_map[rr][cc] > 0 && index_map[rr][cc] != n) // n번섬이 아니면
                    return ans;
                else if(index_map[rr][cc] == 0 && !visited[rr][cc])
                {
                    visited[rr][cc] = true;
                    que.push({rr, cc});
                }
            }
        }
        ans++;
    }
    
    return answer;
}

void bfs(int r, int c, int num)
{
    queue <point> que;
    que.push({r, c});
    visited[r][c] = true;
    index_map[r][c] = num;
    
    while(!que.empty())
    {
        int rr = que.front().first;
        int cc = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int tr = rr + dir[i].first;
            int tc = cc + dir[i].second;
            
            if(tr < 0 || tr >= N) continue;
            if(tc < 0 || tc >= N) continue;
            
            if(!visited[tr][tc] && map[tr][tc] == 1)
            {
                visited[tr][tc] = true;
                index_map[tr][tc] = num;
                que.push({tr, tc});
            }
        }
    }
}

int indexing() {
    int island = 1;
    
    for(int i = 0; i < maps.size(); i++)
    {
        int r = maps[i].first;
        int c = maps[i].second;
        
        if(!visited[r][c])
        {
            bfs(r, c, island); // 섬에 인덱스 붙여주기
            island++;
        }
    }
    return island; // 섬의 개수 반환
}


int main(){
    
    cin >> N;
    
    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++)
        {
            cin >> map[i][j];
            
            if(map[i][j] == 1)
                maps.push_back({i,j}); // 섬인 경우 좌표 저장
        }
    
    island_count = indexing() - 1;
    
    
    for(int i = 1; i<=island_count; i++)
        answer = min(getMinDistance(i), answer);
    
    cout << answer << endl;
    
    return 0;
}

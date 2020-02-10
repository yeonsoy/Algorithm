#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// 다리 만들기 2
// 다리는 ㅣ ㅡ 방향이 있고 해당 방향의 위 아래나 왼쪽 오른쪽에 연결할 나라가 있어야 한다.
// 다리의 길이는 1보다 커야한다.
// 교차하는 다리의 경우 각각의 다리의 크기를 포함한다.
// 0은 바다 1은 땅

// 다리를 만드는 방법.
// 각 섬에 인덱스를 붙여주고, 다리를 세워본다.
// 다리를 세운 뒤 모든 섬에 방문할 수 있으면 통과. 최단거리 구한 뒤 선택한다.

typedef pair<int, int> point;
const int INF = 987654321;

int N, M;
int island_count;
int map[10][10];
int index_map[10][10];
int dist[10][10];
bool visited[10][10];

int answer = INF;
int isUsed[49];

vector <point> maps;
vector <pair<point, int>> bridges; // bridges.first = (a, b), bridges.second = c, a섬에서 b까지 가는 거리 c
vector <point> islands[7]; // 섬의 좌표

point dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int r, int c, point d, int st, int ed, int distance)
{
    int tr = r + d.first;
    int tc = c + d.second;

    if(tr < 0 || tr >= N) return;
    if(tc < 0 || tc >= M) return;
    
    if(map[tr][tc] == 0) // 아직 바다라면
        dfs(tr, tc, d, st, ed, distance + 1); // 계속 다리 세우기
    else {
        if(index_map[tr][tc] == ed) { // 땅에 닿았는데 해당 지점이 목표로 하던 ed 섬이라면
            if(distance > 1) // 다리 길이는 1보다 커야한다
            {
                if(dist[st][ed] > distance) // 저장한 dist보다 작다면
                {
                    dist[st][ed] = distance;
                    dist[ed][st] = distance;
                }
                return;
            }
        }
        else
            return;
    }
    
}

void make_brige(int st, int ed) {
    for(int i = 0; i<islands[st].size(); i++)
    {
        int r = islands[st][i].first;
        int c = islands[st][i].second; // st섬의 좌표
        
        for(int j = 0; j<4; j++) // 4방향으로 st섬에서 ed섬으로 출발
        {
            int tr = r + dir[j].first;
            int tc = c + dir[j].second;
            
            if(tr < 0 || tr >= N) continue;
            if(tc < 0 || tc >= M) continue;
            
            if(map[tr][tc] == 0)
                dfs(r, c, dir[j], st, ed, 0); // 바다라면 다리를 세워서 st에서 ed까지 가는 최단 거리 갱신
        }
    }
}

void getMinDistance() // 다익스트라
{
    for(int i = 1; i < 7; i++)
        for(int j = 1; j < 7; j++)
            dist[i][j] = INF;
    
    for(int i = 1; i <= island_count; i++)
    {
        for(int j = i+1; j <= island_count; j++)
        {
            make_brige(i, j); // 다리 만들기
            if(dist[i][j] == INF) continue; // 여전히 i섬에서 j섬까지 가는 거리가 infinity라면
            bridges.push_back({{i,j}, dist[i][j]});
        }
    }
}

void bfs(int r, int c, int num)
{
    queue <point> que;
    que.push({r, c});
    visited[r][c] = true;
    index_map[r][c] = num;
    islands[num].push_back({r, c});
    
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
            if(tc < 0 || tc >= M) continue;
            
            if(!visited[tr][tc] && map[tr][tc] == 1)
            {
                visited[tr][tc] = true;
                index_map[tr][tc] = num;
                que.push({tr, tc});
                islands[num].push_back({tr, tc});
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

bool isConnected() {
    
    bool canGoIsland[7][7];
    bool checkConnect[7];
    memset(canGoIsland, false, sizeof(canGoIsland));
    memset(checkConnect, false, sizeof(checkConnect));
    
    for(int i = 0; i<bridges.size(); i++)
    {
        if(isUsed[i])
        {
            int st = bridges[i].first.first;
            int ed = bridges[i].first.second;
            
            canGoIsland[st][ed] = true;
            canGoIsland[ed][st] = true; // st에서 ed로 이동하는 다리를 선택했을 때
        }
    }
    
    queue <int> que;
    que.push(1);
    int connected_count = 1;
    checkConnect[1] = true; // 첫 번째 섬에서 시작
    
    while(!que.empty())
    {
        int front = que.front();
        que.pop();
        
        for(int i = 1; i<=island_count; i++)
        {
            if(front == i) continue; // 현재 섬이면

            if(canGoIsland[front][i] && !checkConnect[i]) // 현재 섬에서 i섬에 갈 수 있다면
            {
                checkConnect[i] = true;
                que.push(i);
                connected_count ++;
                
                if(connected_count == island_count)
                    return true;
            }
        }
    }
    
    return false;
}

void solve(int idx, int count, int sum)
{
    if(count >= 1)
        if(isConnected()) // 만약 한 지점에서 모든 곳에 갈 수 있다면
            answer = (answer > sum) ? sum : answer;
    
    for(int i = idx; i<bridges.size(); i++)
    {
        if(!isUsed[i])
        {
            isUsed[i] = true;
            solve(i, count + 1, sum + bridges[i].second); // 다리 개수를 늘려주고, 현재 합 + 다음 다리의 최소 길이
            isUsed[i] = false;
        }
    }
}

int main(){
    
    cin >> N >> M;
    
    for(int i =0; i<N; i++)
        for(int j =0; j<M; j++)
        {
            cin >> map[i][j];
            
            if(map[i][j] == 1)
                maps.push_back({i,j}); // 섬인 경우 좌표 저장
        }
    
    island_count = indexing() - 1;
    getMinDistance();
    solve(0, 0, 0);
    
    if(answer == INF)
        answer = -1;
    
    cout << answer;
    
    return 0;
}

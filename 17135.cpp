#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// 캐슬 디펜스

typedef pair<int, int> point;

int N, M;
int D;
int map[16][16];
int simul[16][16];
bool visited[16][16];
bool isUsed[16];
vector <int> team;
vector <point> enemy;
int answer, result;

void copy() {
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            simul[i][j] = map[i][j];
}

bool compare(pair<point, int> a, pair<point, int> b) {
    if(a.second == b.second)
        return a.first.second < b.first.second; // 거리가 같을 경우 더 왼쪽에 있는 적
    else
        return a.second <= b.second; // 더 가까운 적
}

int getDistance(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

void go() {
    copy();
    
    while(true) {
        enemy.clear();
        
        memset(visited, false, sizeof(visited));
        
        bool isDone = true;
        
        for(int i = 0; i<N; i++)
               for(int j = 0; j<M; j++)
                   if(simul[i][j] == 1) {
                       isDone = false;
                       enemy.push_back({i, j}); // 남아있는 적 저장
                   }
        
        if(isDone) break; // 남은 적이 없는 경우
        
        // 적 공격하기
        point target[3];
        
        for(int i = 0; i<team.size(); i++) {
            int r = N;
            int c = team[i];
            
            vector <pair<point, int>> dead_enemy;
            
            // 사정거리 안에 들어가는 모든 적 저장
            for(int j = 0; j<enemy.size(); j++) {
                int rr = enemy[j].first;
                int cc = enemy[j].second;
                int dist = getDistance(r, c, rr, cc);
                
                if(dist <= D)
                    dead_enemy.push_back({enemy[j], dist});
            }
            
            if(dead_enemy.size() > 0) {
                sort(dead_enemy.begin(), dead_enemy.end(), compare);
                target[i] = dead_enemy[0].first; // 정렬된 가장 가깝고 왼쪽에 있는 적
            }
            else
                target[i] = {-1, -1};
        }
        
        for(int i = 0; i<3; i++) {
            int r = target[i].first;
            int c = target[i].second;
            
            if(r == -1 && c == -1) continue;
            if(!visited[r][c]) {
                visited[r][c] = true;
                simul[r][c] = 0;
                result++;
            }
        }
        
        // 적 이동
        for(int i = enemy.size() - 1; i>=0; i--) {
            int r = enemy[i].first;
            int c = enemy[i].second;
            
            if(simul[r][c] == 0) continue; // 이미 죽은 적
            if(r == N - 1) simul[r][c] = 0; // 바깥으로 나간 적
            else {
                simul[r][c] = 0;
                simul[r + 1][c] = 1;
            }
        }
    }
}

void solve(int idx, int count) {
    
    if(count == 3) {
        result = 0;
        go();
        answer = max(result, answer);
        return ;
    }
    
    for(int i = idx; i<M; i++)
        if(!isUsed[i]) {
            isUsed[i] = true;
            team.push_back(i);
            solve(i, count + 1);
            team.pop_back();
            isUsed[i] = false;
        }
    
}

int main() {
    
    cin >> N >> M >> D;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin >> map[i][j];
    
    // 궁수를 3명 배치, 모든 궁수는 동시에 공격
    // 거리가 D이하면서 가장 가깝고 왼쪽에 있는 적
    
    solve(0, 0);
    
    cout << answer << endl;
    
    return 0;
}

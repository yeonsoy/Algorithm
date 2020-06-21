#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 스타트 택시

typedef pair<int, int> point;
struct passenger {
    point st;
    point ed;
    int idx;
};

int N, M;
long long mount;
int map[21][21];
bool visited[21][21];
passenger passengers[401];
point baekjoon;
point dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool compare (pair<point, int> a, pair<point, int> b)
{
    // 손님 좌표
    point aa = a.first;
    point bb = b.first;
    
    // 거리가 같다면
    if(a.second == b.second) {
        if(aa.first == bb.first)
            return aa.second < bb.second;
        else
            return aa.first < bb.first;
    }
    else
        return a.second < b.second;
}

pair<point, int> getMinPoint() {
    
    memset(visited, false, sizeof(visited));
    queue <pair<point, point>> que;
    que.push({baekjoon, {0, mount}});
    visited[baekjoon.first][baekjoon.second] = true;
    vector <pair<point, int>> temp;
    int min_dist = 2e9;
    
    while(!que.empty()) {
        point p = que.front().first;
        int d = que.front().second.first;
        int remain = que.front().second.second;
        que.pop();
        
        // 손님에 도달한 경우 저장
        if(map[p.first][p.second] > 0 && min_dist >= d) {
            min_dist = d;
            temp.push_back({p, d});
        }
        
        // 연료가 다 떨어진 경우
        if(remain <= 0) continue;
        
        for(int i = 0; i<4; i++)
        {
            int r = p.first + dir[i].first;
            int c = p.second + dir[i].second;
            
            if(r < 0 || r>=N || c < 0 || c >= N) continue;
            if(visited[r][c]) continue;
            if(map[r][c] == -1) continue; // 벽인 경우
            
            que.push({{r, c}, {d + 1, remain - 1}});
            visited[r][c] = true;
        }
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    if(temp.size() > 0)
        return temp[0];
    else
        return {{-1, -1}, 0};
}

int goDest(point st, point ed) {
    
    memset(visited, false, sizeof(visited));
    queue <pair<point, int>> que;
    que.push({st, 0});
    visited[st.first][st.second] = true;
    
    while(!que.empty()) {
        point p = que.front().first;
        int d = que.front().second;
        que.pop();
        
        if(p.first == ed.first && p.second== ed.second)
            return d;
        
        for(int i = 0; i<4; i++)
        {
            int r = p.first + dir[i].first;
            int c = p.second + dir[i].second;
            
            if(r < 0 || r>=N || c < 0 || c >= N) continue;
            if(visited[r][c]) continue;
            if(map[r][c] == -1) continue;
            
            que.push({{r, c}, d + 1});
            visited[r][c] = true;
        }
    }
    
    return -1;
}

int main() {
    
    fastio();
    
    cin >> N >> M >> mount;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) map[i][j] = -1;
        }
    
    cin >> baekjoon.first >> baekjoon.second;
    
    baekjoon.first--;
    baekjoon.second--;
    
    point st, ed;
    for(int i = 0; i<M; i++) {
        cin >> st.first >> st.second >> ed.first >> ed.second;
        st.first--; st.second--;
        ed.first--; ed.second--;
        passengers[i + 1] = {st, ed};
        map[st.first][st.second] = i + 1;
    }
    
    int count = 0;
    while(true) {
        
        pair<point, int> min_point = getMinPoint();
        
        // 아무 승객도 태울 수 없는 경우
        if(min_point.first.first == -1) break;
        
        point cur = min_point.first; // 다음에 태울 손님 위치
        int idx = map[cur.first][cur.second];
        point dest = passengers[idx].ed; // 손님에 해당하는 도착지
        
        // 손님을 태우기 위해 이동
        mount -= min_point.second;
        
        // 손님을 태우다 연료가 바닥난 경우
        if(mount < 0) break;
        
        // 손님을 태움
        map[cur.first][cur.second] = 0;
        
        // 손님을 태우고 도착지로 이동
        int dist = goDest(cur, dest);
        
        // 도착지로 이동할 수 없는 경우
        if(dist < 0) break;
        
        mount -= dist;
        
        // 연료 충전
        if(mount >= 0)
            mount += dist * 2;
        else break;
        
        baekjoon = dest;
        
        count++;
        if(count == M) {
            cout << mount << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
    
    return 0;
}


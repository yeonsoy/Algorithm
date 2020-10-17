#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 치킨 배달

typedef pair<int, int> point;
int N, M;
int map[51][51];
vector <point> chicken;
vector <point> house;
vector <point> open;
int answer = 2e9;

int distance(point a, point b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(int idx, int cnt) {
    
    if(cnt == M) {
        
        int sum = 0;
        for(int i = 0; i<house.size(); i++)
        {
            int check = 2e9;
            for(int j = 0; j<M; j++)
                check = min(check, distance(open[j], house[i]));
            
            sum += check;
        }
        answer = min(answer, sum);
        return;
    }
    
    for(int i = idx; i<chicken.size(); i++) {
        open.push_back(chicken[i]);
        solve(i + 1, cnt + 1);
        open.pop_back();
    }
    
}


int main() {
    
    fastio();
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1)
                house.push_back({i, j});
            else if(map[i][j] == 2)
                chicken.push_back({i, j});
        }
    
    if(chicken.size() == M)
    {
        int sum = 0;
        for(int i = 0; i<house.size(); i++)
        {
            int check = 2e9;
            for(int j = 0; j<M; j++)
                check = min(check, distance(chicken[j], house[i]));
            
            sum += check;
        }
        answer = min(answer, sum);
    }
    else
        solve(0, 0);
    
    cout << answer << endl;
    
    return 0;
}

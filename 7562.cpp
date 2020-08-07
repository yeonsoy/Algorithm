#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 나이트의 이동

typedef pair<int, int> point;
int T;
int I;
bool map[301][301];
point knight, target;
point dir[8] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};

int main() {
    
    cin >> T;
    
    for(int test_case = 0; test_case<T; test_case++)
    {
        cin >> I;
        
        int answer = 0;
        memset(map, false, sizeof(map));
        
        cin >> knight.first >> knight.second;
        cin >> target.first >> target.second;
        
        queue <pair<point, int>> que;
        que.push({knight, 0});
        map[knight.first][knight.second] = true;
        
        while(!que.empty()) {
            point p = que.front().first;
            int d = que.front().second;
            que.pop();
            
            if(p.first == target.first && p.second == target.second) {
                answer = d;
                break;
            }
            
            for(int i = 0; i<8; i++) {
                int r = p.first + dir[i].first;
                int c = p.second + dir[i].second;
                
                if(r < 0 || r >= I || c < 0 || c >= I) continue;
                if(map[r][c]) continue;
                
                map[r][c] = true;
                que.push({{r, c}, d + 1});
                
            }
        }
        
        cout << answer << endl;
        
    }
    
    return 0;
}

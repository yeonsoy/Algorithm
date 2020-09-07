#include <string>
#include <vector>
#include <queue>
using namespace std;

// 경주로 건설

typedef pair<int, int> point;
typedef pair<point, point> road;
point dir[4] = {{0,1}, {1,0}, {-1,0}, {0, -1}};

int solution(vector<vector<int>> board) {
    int answer = 2e9;
    int N = (int) board.size();
    
    queue <road> que;
    que.push({{0, 0}, {0, -1}});
    board[0][0] = 1;
    
    while(!que.empty()) {
        point p = que.front().first;
        int cost = que.front().second.first;
        int d = que.front().second.second;
        que.pop();
        
        if(p.first == N - 1 && p.second == N - 1) {
            answer = min(answer, cost);
            continue;
        }
        
        for(int i = 0; i<4; i++) {
            int r = p.first + dir[i].first;
            int c = p.second + dir[i].second;
            
            if(r < 0 || r >= N || c < 0 || c >= N) continue;
            
            int next = 0;
            
            // 처음 시작점이거나 기존 방향과 같은 방향이라면
            if(d == -1 || d == i)
                next = cost + 100;
            else
                next = cost + 400 + 100 + 100;
            
            if(board[r][c] == 0 || board[r][c] >= next) {
                board[r][c] = next;
                que.push({{r, c}, {next, i}});
            }
        }
    }
    
    return answer;
}

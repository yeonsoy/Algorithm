#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// 블록 이동하기

typedef pair<int, int> point;
typedef pair<point, point> robot;
point dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool visited[101][101][101][101];

point isPossible(point a, point b, int pivot, int isClockwise, vector<vector<int>> board){
    
    int N = (int) board.size();
    
    if (a.first == b.first) {
        if (pivot == 0) {
            if (a.second<b.second) {
                if (isClockwise) {
                    if(a.first + 1 >= N || a.second + 1 >= N) return {-1, -1};
                    
                    if(board[a.first + 1][a.second] == 0 && board[a.first + 1][a.second + 1] == 0)
                        return {a.first + 1, a.second};
                }
                else{
                    if(a.first < 1 || a.second + 1 >= N) return {-1, -1};
                    
                    if(board[a.first - 1][a.second] == 0 && board[a.first - 1][a.second + 1] == 0)
                        return {a.first - 1, a.second};
                }
            }
            else{
                if (isClockwise) {
                    if(a.first < 1 || a.second < 1) return {-1, -1};
                    
                    if(board[a.first - 1][a.second] == 0 && board[a.first - 1][a.second - 1] == 0)
                        return {a.first - 1, a.second};
                }
                else{
                    if(a.first + 1 >= N || a.second < 1) return {-1, -1};
                    if (board[a.first + 1][a.second] == 0 && board[a.first + 1][a.second - 1] == 0)
                        return {a.first + 1, a.second};
                }
            }
        }
        else{
            if (a.second < b.second) {
                if (isClockwise) {
                    if(b.first < 1 || b.second < 1) return {-1, -1};
                    
                    if(board[b.first - 1][b.second] == 0 && board[b.first - 1][b.second - 1] == 0)
                        return {b.first - 1, b.second};
                }
                else{
                    if(b.first + 1 >= N || b.second < 1) return {-1, -1};
                    
                    if (board[b.first + 1][b.second] == 0 && board[b.first + 1][b.second - 1] == 0)
                        return {b.first + 1, b.second};
                }
            }
            else{
                if (isClockwise) {
                    if(b.first + 1 >= N || b.second + 1 >= N) return {-1, -1};
                    
                    if (board[b.first + 1][b.second] == 0 && board[b.first + 1][b.second + 1] == 0)
                        return {b.first + 1, b.second};
                }
                else{
                    if(b.first < 1 || b.second + 1 >= N) return {-1, -1};
                    
                    if (board[b.first - 1][b.second] == 0 && board[b.first - 1][b.second + 1] == 0)
                        return {b.first-1, b.second};
                }
            }
        }
    }
    else{
        if(pivot == 0){
            if(a.first < b.first){
                if (isClockwise) {
                    if(a.first + 1 >= N || a.second < 1) return {-1, -1};
                    
                    if (board[a.first][a.second - 1] == 0 && board[a.first + 1][a.second - 1] == 0)
                        return {a.first, a.second - 1};
                }
                else{
                    if(a.first + 1 >= N || a.second + 1 >= N) return {-1, -1};
                    
                    if (board[a.first][a.second + 1] == 0 && board[a.first + 1][a.second + 1] == 0)
                        return {a.first, a.second + 1};
                }
            }
            else{
                if (isClockwise) {
                    if(a.first < 1 || a.second + 1 >= N) return {-1, -1};
                    
                    if (board[a.first][a.second + 1] == 0 && board[a.first - 1][a.second + 1] == 0)
                        return {a.first, a.second + 1};
                }
                else{
                    if(a.first < 1 || a.second < 1) return {-1, -1};
                    
                    if (board[a.first][a.second - 1] == 0 && board[a.first - 1][a.second - 1] == 0)
                        return {a.first, a.second - 1};
                }
            }
        }
        else{
            if(a.first > b.first){
                if (isClockwise) {
                    if(b.first + 1 >= N || b.second < 1) return {-1, -1};
                    
                    if (board[b.first][b.second - 1] == 0 && board[b.first + 1][b.second - 1] == 0)
                        return {b.first, b.second - 1};
                }
                else{
                    if(b.first + 1 >= N || b.second + 1 >= N) return {-1, -1};
                    
                    if (board[b.first][b.second + 1] == 0 && board[b.first + 1][b.second + 1] == 0)
                        return {b.first, b.second+1};
                }
            }
            else{
                if (isClockwise) {
                    if(b.first < 1 || b.second + 1 >= N) return {-1, -1};
                    
                    if (board[b.first][b.second + 1] == 0 && board[b.first - 1][b.second + 1] == 0)
                        return {b.first,  b.second+1};
                }
                else{
                    if(b.first < 1 || b.second < 1) return {-1, -1};
                    
                    if (board[b.first][b.second - 1] == 0 && board[b.first - 1][b.second - 1] == 0)
                        return {b.first, b.second - 1};
                }
            }
        }
        
    }
    return {-1, -1};
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = (int) board.size();
    
    queue<pair<robot, int>> que;
    que.push({{{0, 0}, {0, 1}}, 0});
    visited[0][0][0][1] = true;
    
    
    while (!que.empty()) {
        robot cur = que.front().first;
        int d = que.front().second;
        que.pop();
        
        point a = cur.first;
        point b = cur.second;
        
        if((a.first == N - 1 && a.second == N - 1) || (b.first == N - 1 && b.second == N - 1))
            return d;
        else{
            // 4방향 체크 : right left up down
            for(int i = 0; i<4; i++) {
                point na = {a.first + dir[i].first, a.second + dir[i].second};
                point nb = {b.first + dir[i].first, b.second + dir[i].second};
                
                if(na.first < 0 || na.first >= N || na.second < 0 ||  na.second >= N) continue;;
                if(nb.first < 0 || nb.first >= N || nb.second < 0 ||  nb.second >= N) continue;;
                if(board[na.first][na.second] == 1 || board[nb.first][nb.second] == 1) continue;
                if(visited[na.first][na.second][nb.first][nb.second] || visited[nb.first][nb.second][na.first][na.second]) continue;
                
                visited[na.first][na.second][nb.first][nb.second] = true;
                que.push({{na, nb}, d + 1});
            }
            
            for(int i = 0; i<2; i++)
                for(int j = 0; j<2; j++) {
                    point next = isPossible(a, b, i, j, board);
                    
                    if(next.first == -1) continue;
                    
                    if (i == 0) {
                        if(visited[a.first][a.second][next.first][next.second] || visited[next.first][next.second][a.first][a.second]) continue;
                        
                        visited[a.first][a.second][next.first][next.second] = true;
                        que.push({{a, next}, d + 1});
                    }
                    else {
                        if(visited[next.first][next.second][b.first][b.second] || visited[b.first][b.second][next.first][next.second]) continue;
                        
                        visited[next.first][next.second][b.first][b.second] = true;
                        que.push({{next, b}, d + 1});
                    }
                }
        }
    }

    return answer;
}

int main() {
    
    cout << solution({{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}});
    
    return 0;
}

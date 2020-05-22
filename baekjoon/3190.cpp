#include <iostream>
#include <deque>
using namespace std;

// 뱀

typedef pair<int, int> point;
typedef pair<point, int> game;

int N, K;
int L;
int map[101][101];
deque<point> snake;
point dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int answer;
int length;

bool goSnake(int d) {
    
    answer ++;
    // 이동할 다음 칸
    point next = {snake.front().first + dir[d].first, snake.front().second + dir[d].second};
    
    if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= N) // 벽과 부딪혔을 때
        return false;
    
    if(map[next.first][next.second] == 2) // 자기 자신의 몸과 부딪혔을 때
        return false;
    
    
    // 가능하다면 머리 이동
    snake.push_front(next);
    
    // 사과가 없었으면
    if(map[next.first][next.second] != 1) {
        map[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
        
        length --;
    }
    
    map[next.first][next.second] = 2;
    
    length++;
    
    
    
    
    return true;
    
}

int main() {
    
    cin >> N >> K;
    
    for(int i = 0; i<K; i++)
    {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }
    
    cin >> L;
    
    int X;
    char C;
    
    snake.push_back({0, 0});
    length++;
    map[0][0] = 2;
    bool flag = true;
    int d = 1;
    
    for(int i = 0; i<L; i++) {
        
        cin >> X >> C;
        
        while(true && flag) {
            if(length > 0) {
                flag = goSnake(d);
                if(!flag)
                    break;
            }
            
            if(answer == X) {
                if(C == 'L') {
                    d++;
                    if(d > 3) d = 0;
                }
                else {
                    d--;
                    if(d < 0) d = 3;
                }
                if(i < L - 1) break;
            }
            
            if(!flag) break;
        }
        
        
    }
    
    cout << answer << endl;
    
    return 0;
}

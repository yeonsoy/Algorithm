#include <iostream>
#include <queue>

using namespace std;

// 체스
// Queen, Knight, Pawn
// 안전한 칸은 몇 칸인가
// Queen : 가로, 세로, 대각선으로 갈 수 있는 만큼 최대한 많이 이동 가능 단, 장애물이 있다면 이동 불가.
// Knight : 2*3의 직사각형의 반대쪽 꼭짓점으로 이동 가능. 장애물이 있어도 이동 가능.
// Pawn : 상대팀의 말은 잡을 수 없고, 장애물 역할.

typedef pair<int, int> point;

int N, M;
int chess[1002][1002];
queue<point> queen, knight;

point knight_dir[8] = {{-2, -1}, {-1, 2}, {1, 2}, {2, 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, 1}};
point queen_dir[8] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void solve() {
    
    while(!queen.empty())
    {
        auto front = queen.front();
        queen.pop();
        
        for(int i = 0; i<8; i++)
        {
            int r = front.first;
            int c = front.second;
            
            while(true)
            {
                r += queen_dir[i].first;
                c += queen_dir[i].second;
                
                if(r <= 0 || r > N) break;
                if(c <= 0 || c > M) break;
                
                if(chess[r][c] == 1 || chess[r][c] == 2 || chess[r][c] == 3)
                    break;
                
                chess[r][c] = 4;
            }
        }
    }
    
    while(!knight.empty())
    {
        auto front = knight.front();
        knight.pop();
        
        for(int i =0; i<8; i++)
        {
            int r = front.first + knight_dir[i].first;
            int c = front.second + knight_dir[i].second;
            
            if(r <= 0 || r > N) continue;
            if(c <= 0 || c > M) continue;
            
            if(chess[r][c] == 0)
                chess[r][c] = 4;
        }
    }
    
    int answer = 0;
    for(int i = 1; i<=N; i++)
        for(int j =1; j<=M; j++)
            if(chess[i][j] == 0)
                answer++;
    
    cout << answer << endl;
}

int main() {
    
    cin >>N >> M;
    
    int q, k, p;
    
    cin >> q;
    for(int i =0; i<q; i++)
    {
        int r, c;
        cin >> r >> c;
        queen.push({r, c});
        chess[r][c] = 1;
    }
    
    cin >> k;
    for(int i =0; i<k; i++)
    {
        int r, c;
        cin >> r >> c;
        knight.push({r, c});
        chess[r][c] = 2;
    }
    
    cin >> p;
    for(int i =0; i<p; i++)
    {
        int r, c;
        cin >> r >> c;
        chess[r][c] = 3;
    }
    
    solve();
    return 0;
}

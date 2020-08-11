#include <iostream>
using namespace std;

// 지뢰찾기

typedef pair<int, int> point;
int N;
char map[101][101];
int answer;
point dir[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool isPossible(int r, int c) {
    for(int i = 0; i<8; i++){
        int rr = r + dir[i].first;
        int cc = c + dir[i].second;
        
        if(rr < 0 || rr >= N || cc < 0 || cc >= N) continue;
        
        if(map[rr][cc] == '0')
            return false;
    }
    
    return true;
}

void setBomb(int r, int c) {
    for(int i = 0; i<8; i++){
        int rr = r + dir[i].first;
        int cc = c + dir[i].second;
        
        if(rr < 0 || rr >= N || cc < 0 || cc >= N) continue;
        
        if(map[rr][cc] >= '0' && map[rr][cc] <= '9')
            map[rr][cc] --;
    }
}

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin >> map[i][j];
    
    if(N > 1)
        answer = (N - 2) * (N - 2);
    
    for(int i = 1; i<N-1; i++)
        for(int j = 1; j<N-1; j++)
        {
            if(i == 1 || i == N - 2 || j == 1 || j == N - 2) {
                if(isPossible(i,j))
                    setBomb(i,j);
                else answer--;
            }
        }
    
    cout << answer << endl;
    
    return 0;
}

#include <iostream>
using namespace std;

// 십자가 2개 놓기

typedef pair<int, int> point;
int N, M;
int answer;
char map[16][16];
char first_map[16][16];
char second_map[16][16];

point dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void copy_map(char a[16][16], char b[16][16]) {
    for(int i = 0; i<N; i++)
        for(int j =0; j<M; j++)
            a[i][j] = b[i][j];
}

bool isPossible(int r, int c, int length, char m[16][16]) {
    for(int i = 0; i<4; i++) {
        int rr = r + dir[i].first * length;
        int cc = c + dir[i].second * length;
        
        if (rr < 0 || rr >= N || cc < 0 || cc >= M)
            return false;
        
        if (m[rr][cc] != '#')
            return false;
    }
    
    return true;
}

void setCross(int r, int c, int length, char m[16][16]) {
    for(int i = 0; i<4; i++) {
        int rr = r + dir[i].first * length;
        int cc = c + dir[i].second * length;
        
        m[rr][cc] = '*';
    }
}

int main() {
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j =0; j<M; j++)
            cin >> map[i][j];
    
    for(int i = 0; i<N; i++)
        for(int j =0; j<M; j++)
        {
            // 붙일 수 없는 칸이라면
            if(map[i][j] != '#') continue;
            
            copy_map(first_map, map);
            
            int first_length = 1;
            int first_cross = 1;
            first_map[i][j] = '1';
            
            while(true) {
                
                if(!isPossible(i, j, first_length, first_map))
                    break;
                else
                    setCross(i, j, first_length, first_map);
                
                first_length++;
                first_cross += 4;
            }
            
            
            for(int k = 0; k<N; k++)
                for(int m = 0; m<M; m++)
                {
                    if(first_map[k][m] != '#') continue;
                    copy_map(second_map, first_map);
                    
                    int second_length = 1;
                    int second_cross = 1;
                    
                    while(true) {
                        if(!isPossible(k, m, second_length, second_map))
                            break;
                        else
                            setCross(k, m, second_length, second_map);
                        
                        second_length++;
                        second_cross += 4;
                    }
                    
                    answer = max(first_cross * second_cross, answer);
                }
            
        }
    
    cout << answer << endl;
    
    return 0;
}

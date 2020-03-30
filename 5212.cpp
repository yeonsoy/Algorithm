#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 지구 온난화

typedef pair<int, int> point;
int R, C;
char map[11][11];
char temp[11][11];
vector <char> check;
point dir[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void solve() {
    
    memset(temp, '.', sizeof(temp));
    
    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++) {
            
            int count = 0;
            
            for(int k = 0; k<4; k++) {
                int r = i + dir[k].first;
                int c = j + dir[k].second;
                
                if(r < 0 || r >= R || c < 0 || c>= C) {
                    count ++;
                    continue;
                }
                
                if(map[r][c] == '.') count++;
            }
            
            if(count < 3)
                check.push_back(map[i][j]);
            else
                check.push_back('.');
        }
        
        for(int k = 0; k<check.size(); k++)
            temp[i][k] = check[k];
        
        check.clear();
    }
    
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
            map[i][j] = temp[i][j];
}

void answer() {
    
    int lt_r = -1;
    int rb_r = -1;
    for(int i = 0; i<R; i++) {
        bool flag = true;
        for(int j = 0; j<C; j++)
            if(map[i][j] != '.') {
                flag = false;
                break;
            }
        
        if(flag && lt_r == -1)
            lt_r = i;
        if(flag)
            rb_r = i;
    }
    
    
}


int main() {
    
    cin >> R >> C;
    
    memset(map, '.', sizeof(map));
    
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
            cin >> map[i][j];
    
    solve();
    
    int startRow = -1;
    int endRow = -1;
    int startColumn = -1;
    int endColumn = -1;
    
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            if(map[i][j] == 'X' && startRow == -1) startRow = i;
            if(map[i][j] == 'X') endRow = max(endRow, i);
        }
    
    for(int i=0; i<C; i++)
        for(int j=0; j<R; j++) {
            if(map[j][i] == 'X' && startColumn == -1) startColumn = i;
            if(map[j][i] == 'X') endColumn = max(endColumn, i);
        }
    
    for(int i=startRow; i<=endRow; i++) {
        for(int j=startColumn; j<=endColumn; j++)
            cout << map[i][j];
        cout << endl;
    }
    
    return 0;
}

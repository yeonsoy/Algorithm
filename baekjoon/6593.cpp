#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 상범 빌딩

struct point {
    int l;
    int r;
    int c;
};

int L, R, C;
int building[31][31][31];

point dir[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

int solve(point st, point ed) {
    
    queue <pair<point, int>> que;
    bool visited[31][31][31];
    memset(visited, false, sizeof(visited));
    que.push({st, 0});
    visited[st.l][st.r][st.c] = true;
    
    while(!que.empty()) {
        int l = que.front().first.l;
        int r = que.front().first.r;
        int c = que.front().first.c;
        
        int count = que.front().second;
        que.pop();
        
        if(l == ed.l && r == ed.r && c == ed.c) return count;
        
        for(int i = 0; i<6; i++) {
            
            int ll = l + dir[i].l;
            int rr = r + dir[i].r;
            int cc = c + dir[i].c;
            
            if(ll < 0 || ll >= L) continue;
            if(rr < 0 || rr >= R) continue;
            if(cc < 0 || cc >= C) continue;
            
            if(!visited[ll][rr][cc] && building[ll][rr][cc] == 0)
            {
                visited[ll][rr][cc] = true;
                que.push({{ll, rr, cc}, count + 1});
            }
            
        }
    }
    
    
    return -1;
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true) {
        cin >> L >> R >> C;
        
        if(L == 0 && R == 0 && C == 0) break;
        
        memset(building, 0, sizeof(building));
        
        point st, ed;
        for(int i = 0; i<L; i++)
            for(int j = 0; j<R; j++) {
                string str;
                
                cin >> str;
                for(int k = 0; k<C; k++)
                {
                    if(str[k] == 'S') {
                        st.l = i;
                        st.r = j;
                        st.c = k;
                    }
                    else if(str[k] == '#')
                        building[i][j][k] = 1;
                    else if(str[k] == 'E')
                    {
                        ed.l = i;
                        ed.r = j;
                        ed.c = k;
                    }
                }
            }
        
        int answer = solve(st, ed);
        if(answer == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << answer << " minute(s)." << endl;
    }
    
    return 0;
    
}

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

// Puyo Puyo

typedef pair<int, int> point;

char map[12][6];
bool visited[12][6];
int temp_count;
int answer;
vector<point> boom_temp, boom;

point dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int r, int c)
{
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dir[i].first;
        int cc = c + dir[i].second;
        
        if (rr < 0 || cc < 0 || rr >= 12 || cc >= 6) continue;
        if (map[rr][cc] == '.') continue;
        if (visited[rr][cc]) continue;
        
        if (map[r][c] != map[rr][cc]) continue;
        
        temp_count++;
        visited[rr][cc] = true;
        boom_temp.push_back(make_pair(rr, cc));
        dfs(rr, cc);
    }
}

void solve() {
    
    bool flag;
    while (true)
    {
        flag = false;
        memset(visited, false, sizeof(visited));
        boom.clear();
        
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (map[i][j] != '.' && !visited[i][j])
                {
                    temp_count = 1;
                    boom_temp.push_back(make_pair(i, j));
                    visited[i][j] = true;
                    dfs(i, j);
                    
                    // 4개 이상 모이면 터진다
                    if (temp_count >= 4)
                    {
                        flag = true;
                        for (int i = 0; i < boom_temp.size(); i++)
                            boom.push_back(boom_temp[i]);
                    }
                    
                    boom_temp.clear();
                }
            }
        }
        
        for (int i = 0; i < boom.size(); i++)
        {
            int r = boom[i].first;
            int c = boom[i].second;
            
            map[r][c] = '.';
        }
        
        for (int i = 10; i >= 0; i--)
        {
            for (int j = 0; j < 6; j++)
            {
                if (map[i][j] == '.') continue;
                int temp = i;
                
                while (true)
                {
                    if (temp == 11 || map[temp + 1][j] != '.') break;
                    
                    map[temp + 1][j] = map[temp][j];
                    map[temp][j] = '.';
                    temp++;
                }
            }
        }
        
        if (!flag) break;
        else answer++;
    }
}


int main() {
    
    for(int i = 0; i<12; i++)
        for(int j = 0; j<6; j++)
            cin >> map[i][j];
    
    solve();
    
    cout << answer << endl;
    
    return 0;
}

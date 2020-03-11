#include <iostream>
#include <vector>
using namespace std;

// 감시 피하기
typedef pair<int, int> point;
int N;

point dir[4] = {{1,0}, {-1, 0}, {0,1}, {0, -1}};

char hallway[6][6];
bool isUsed[6][6];
vector<point> student;
vector<point> teacher;
vector<point> obstacle;
bool answer;


bool bfs() {
    char temp[6][6];
    for(int i = 0; i<N; i++)
    for(int j = 0; j<N; j++)
        temp[i][j] = hallway[i][j];
    
    for(int i =0;i<obstacle.size(); i++)
        temp[obstacle[i].first][obstacle[i].second] = 'O';
    
    for(int i = 0; i<teacher.size(); i++) {
        
        for(int j = 0; j<4; j++) {
            int k = 1;
            while(true) {
            int r = teacher[i].first + dir[j].first * k;
            int c = teacher[i].second + dir[j].second * k;
                if(r < 0 || r>= N) break;
                if(c < 0 || c>= N) break;
                if(temp[r][c] == 'O') break;
                
                if(temp[r][c] == 'S')
                    return false;
                
                k++;
            }
        }
        
    }
    
    return true;
    
}

void solve(int count) {
    
    if(count == 3)
    {
        if(bfs())
        {
            cout << "YES" << endl;
            exit(0);
        }
        
        return;
    }
    
   for(int i = 0; i<N; i++)
       for(int j = 0; j<N; j++) {
           if(hallway[i][j] == 'X' && !isUsed[i][j])
           {
               isUsed[i][j] = true;
               obstacle.push_back({i, j});
               solve(count + 1);
               isUsed[i][j] = false;
               obstacle.pop_back();
           }
       }
}

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++) {
            cin >> hallway[i][j];
            if(hallway[i][j] == 'S')
                student.push_back({i, j});
            else if(hallway[i][j] == 'T')
                teacher.push_back({i, j});
        }
    
    solve(0);
    
    cout << "NO" << endl;
    
    
    return 0;
}

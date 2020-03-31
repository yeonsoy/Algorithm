#include <iostream>
using namespace std;

// 숫자 정사각형

typedef pair<int, int> point;
int N, M;
int map[51][51];
int answer;


int main() {
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            scanf("%1d", &map[i][j]);
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++) {
            
            for(int k = 0; k<51; k++) {
                point lt = {i, j};
                point rt = {i, j + k};
                point lb = {i + k, j};
                point rb = {i + k, j + k};
                
                if(i + k >= N || j + k >=M) break;
                
                if(map[lt.first][lt.second] == map[rt.first][rt.second]
                   && map[rt.first][rt.second] == map[lb.first][lb.second]
                   && map[lb.first][lb.second] == map[rb.first][rb.second]) {
                    answer = max(answer, k + 1);
                }
            }
        }
    
    cout << answer * answer;
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// 

typedef pair<int, int> point;
int N, M;
int map[1001][1001];
bool visited[1001][1001];
int count_map[1000 * 1000 / 2 + 1];
int count_visit[1000 * 1000 / 2 + 1];

int shape_count;
int answer;
point dir[4] = {{-1, 0}, {1,0}, {0,1}, {0, -1}};

void bfs(int r, int c, int index) {
    
    queue <point> que;
    que.push({r, c});
    visited[r][c] = true;
    map[r][c] = shape_count;
    count_map[shape_count]++;
    
    while(!que.empty()) {
        point front= que.front();
        que.pop();
        
        for(int i = 0; i<4; i++) {
            int rr = front.first + dir[i].first;
            int cc = front.second + dir[i].second;
            
            if(rr < 0 || rr >= N || cc < 0 || cc >= M) continue;
            
            if(!visited[rr][cc] && map[rr][cc] == 1) {
                visited[rr][cc] = true;
                map[rr][cc] = shape_count;
                count_map[shape_count]++;
                que.push({rr, cc});
            }
        }
        
    }
    
}

void indexing() {
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            if(!visited[i][j] && map[i][j] == 1)
                bfs(i, j, ++shape_count);
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] ==0) visited[i][j] = true;
        }

    indexing();
    int used_idx[4] = {0, 0, 0, 0};
    
    for (int i = 0; i < N; i++)
           for (int j = 0; j < M; j++)
            if (map[i][j] == 0)
            {
                int temp = 1, pivot = 0;
                for (int k = 0; k < 4; k++)
                {
                    int rr = i + dir[k].first;
                    int cc = j + dir[k].second;

                    if (rr < 0 || rr >= N || cc < 0 || cc >= M)continue;

                    int pos = map[rr][cc];

                    if (!count_visit[pos] && pos != 0)
                    {
                        temp += count_map[pos];
                        count_visit[pos] = true;
                        used_idx[pivot++] = pos; // 사용한 인덱스 저장
                    }
                }
                answer = max(answer, temp);
                for (int t = 0; t < pivot; t++)
                    count_visit[used_idx[t]] = false;
            }
    
    cout << answer << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> point;

// 연구소 3
// 비활성화 바이러스가 활성화 바이러스를 만나면 활성화된다.

int N, M;
int lab[50][50];
int day[50][50];
bool isUsed[10];
int answer = 987654321;
int zero_count;

vector <point> virus;

point dir[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

void cpyLab(int v_lab[50][50])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            v_lab[i][j] = lab[i][j];
}

void bfs()
{
    int virus_lab[50][50];
    cpyLab(virus_lab);
    memset(day, -1, sizeof(day));
    int isHealthy = zero_count;
    int total_day = 0;
    
    queue <point> que;
    for (int i = 0; i < virus.size(); i++)
    {
        if (isUsed[i]) {
            que.push(virus[i]);
            day[virus[i].first][virus[i].second] = 0;
        }
        else virus_lab[virus[i].first][virus[i].second] = 3;
    }
    
    while (!que.empty())
    {
        auto front = que.front();
        int rr = front.first;
        int cc = front.second;
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int tr = rr + dir[i].first;
            int tc = cc + dir[i].second;

            if (tr < 0 || tr >= N)
                continue;

            if (tc < 0 || tc >= N)
                continue;

            if (virus_lab[tr][tc] == 0 || virus_lab[tr][tc] == 3)
            {
                day[tr][tc] = day[rr][cc] + 1;
                
                if(virus_lab[tr][tc] == 0)
                {
                    isHealthy--;
                    total_day = day[tr][tc];
                }
                
                virus_lab[tr][tc] = 2;
                que.push({ tr, tc });
            }
        }
    }

    if(isHealthy == 0)
        answer = (answer > total_day) ? total_day : answer;
}

void solve(int n, int count) {

    if (count == M)
    {
        bfs();
        return; // 모든 바이러스를 선택했을 때
    }

    for (int i = n; i < virus.size(); i++)
    {
        if (!isUsed[i]) {
            isUsed[i] = true;
            solve(i + 1, count + 1);
            isUsed[i] = false;
        }
    }

}

int main(int argc, char* argv[])
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 2)
                virus.push_back({ i, j });
            
            else if(lab[i][j] == 0) zero_count++;
        }

    if(zero_count == 0)
        cout << 0;
    
    else {
        solve(0, 0);

        if (answer == 987654321)
            cout << -1;
        else
            cout << answer;
    }
}

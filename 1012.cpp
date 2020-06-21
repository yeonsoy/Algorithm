#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 유기농 배추

int T;
vector <int> answer;
int field[51][51];
bool visited[51][51];
int M, N, K;

void solve(int x, int y) {

    queue <pair<int, int>> q;
    q.push({ x, y });

    pair<int, int> dir[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = front.first + dir[i].first;
            int y = front.second + dir[i].second;

            if (x < 0 || x> M || y<0 || y>N)
                continue;

            if (field[x][y] == 1)
            {
                field[x][y] = 0;
                q.push({ x,y });
            }
        }
    }

}

int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;

        int ans = 0;

        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
            {
                field[j][k] = 0;
                visited[j][k] = false;
            }

        for (int j = 0; j < K; j++)
        {
            int x = 0;
            int y = 0;
            cin >> x >> y;
            field[x][y] = 1;
        }

        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
            {
                if (field[j][k] == 1)
                {
                    solve(j, k);
                    ans++;
                }
            }

        answer.push_back(ans);
    
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;
    return 0;
}

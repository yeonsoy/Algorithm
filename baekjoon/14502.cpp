#include <iostream>
#include <queue>
using namespace std;

int N, M;
int maps[8][8];
int answer = 0;

// 연구소

void bfs()
{
    int count = 0;
    int check_map[8][8];
    bool visited[8][8];

    queue <pair<int, int>> q;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
            check_map[i][j] = maps[i][j];

            if (check_map[i][j] == 2)
            {
                q.push({ i,j });
                visited[i][j] = true;
            }
        }

    pair<int, int> dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int dx = front.first + dir[i].first;
            int dy = front.second + dir[i].second;

            if (dx < 0 || dx >= N)
                continue;

            if (dy < 0 || dy >= M)
                continue;

            if (check_map[dx][dy] == 0 && !visited[dx][dy])
            {
                check_map[dx][dy] = 2;
                visited[dx][dy] = true;
                q.push({ dx, dy });
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (check_map[i][j] == 0)
                count++;

    answer = (answer > count) ? answer : count;
}

void makeWall(int n)
{
    if (n == 3)
    {
        bfs();
        return;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (maps[i][j] == 0)
            {
                maps[i][j] = 1;
                makeWall(n + 1);
                maps[i][j] = 0;
            }
        }
}


int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> maps[i][j];


    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (maps[i][j] == 0)
            {
                maps[i][j] = 1;
                makeWall(1);
                maps[i][j] = 0;
            }
        }

    cout << answer;

    return 0;
}

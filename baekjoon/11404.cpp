#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;

int n; // 도시의 개수
int m; // 버스의 개수
int **bus;

void floyd()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (bus[j][i] != INF && bus[i][k] != INF) // j에서 k로 이동할 때 i정점을 거칠 수 있는 경우
                    bus[j][k] = (bus[j][k] > (bus[j][i] + bus[i][k])) ? (bus[j][i] + bus[i][k]) : bus[j][k];
}

int main()
{
    cin >> n >> m; // 1 ~ 100

    bus = new int*[n + 1];

    for (int i = 0; i <= n; i++)
        bus[i] = new int[n + 1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            bus[i][j] = INF;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (bus[a - 1][b - 1] > c)
            bus[a - 1][b - 1] = c;
    }

    floyd();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || bus[i][j] == INF)
                cout << 0 << " ";
            else
                cout << bus[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

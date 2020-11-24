#include <iostream>
using namespace std;

// 체스판 다시 칠하기

int N, M;
char map[51][51];

int check(int r, int c) {
    int black = 0, white = 0;

    for (int i = r; i < r + 8; i++)
        for (int j = c; j < c + 8; j++)
        {
            if ((i + j) % 2 == 0 && map[i][j] == 'B')
                black++;
            if ((i + j) % 2 == 1 && map[i][j] == 'W')
                black++;

            if ((i + j) % 2 == 0 && map[i][j] == 'W')
                white++;
            if ((i + j) % 2 == 1 && map[i][j] == 'B')
                white++;
        }

    return min(black, white);
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];


    int answer = 2e9;
    for (int i = 0; i <= N - 8; i++)
        for (int j = 0; j <= M - 8; j++)
            answer = min(answer, check(i, j));

    cout << answer << endl;

    return 0;
}

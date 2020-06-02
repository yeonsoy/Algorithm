#include <iostream>
#include <vector>
using namespace std;

int N;
int chess[15]; // n은 0 ~ 15사이, 체스의 Column
int answer;

void setQueen(int row)
{
    bool isVerify;

    if (row == N)
    {
        answer++;
        return;
    }
    for (int x = 0; x < N; x++)
    {
        isVerify = true; // 퀸을 배치할 수 있도록
        for (int y = 0; y < row; y++)
        {
            // 현재 놓으려는 퀸의 위치 chess[y] = x (x, y)
            if (chess[y] == x) // y Coulum 에 퀸이 존재한다면
            {
                isVerify = false;
                break;
            }
            // (x,y) 과 (x + n, y + n) 은 대각선 위치에 있으므로
            // x - (x + n)과 y - (y + n)을 비교하여 대각선인지 아닌지를 구할 수 있다
            if (abs(y - row) == abs(x - chess[y])) // 대각선에 퀸이 존재한다면
            {
                isVerify = false;
                break;
            }
        }
        if (isVerify) { // 퀸을 놓을 수 있다면
            chess[row] = x;
            setQueen(row + 1);
        }
    }
}

int main(void)
{
    cin >> N;

    answer = 0;
    setQueen(0);

    cout << answer;

    return 0;
}

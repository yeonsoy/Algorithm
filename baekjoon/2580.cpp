#include <iostream>
#include <vector>
using namespace std;

// 스도쿠

struct point {
    int x;
    int y;
};

int sudoku[9][9];
vector <point> blank;

bool checkRow(int x, int n)
{
    for (int i = 0; i < 9; i++)
        if (sudoku[x][i] == n)
            return false;

    return true;
}

bool checkColumn(int y, int n)
{
    for (int i = 0; i < 9; i++)
        if (sudoku[i][y] == n)
            return false;

    return true;
}

bool checkSquare(int x, int y, int n)
{
    int tx = (x / 3) * 3;
    int ty = (y / 3) * 3;

    for (int i = tx; i < tx + 3; i++)
        for (int j = ty; j < ty + 3; j++)
            if(sudoku[i][j] == n)
                return false;

    return true;
}

bool verifySudoku(int x, int y, int n)
{
    return (checkRow(x, n) && checkColumn(y, n) && checkSquare(x, y, n));
}

void print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << sudoku[i][j] << " ";
        cout << endl;
    }
}


void dfs(int n) {
    if (n == blank.size()) { // 빈칸 만큼 dfs를 실행했으면 (빈칸을 전부 채웠으면)
        print(); // 답 출력
        exit(0);
    }

    for (int i = 0; i < 9; i++) {
        int x = blank[n].x;
        int y = blank[n].y;

        if (verifySudoku(x, y, i + 1)) { // 조건에 맞으면 입력
            sudoku[x][y] = i + 1;
            dfs(n + 1); // 다음 칸 채우기
            sudoku[x][y] = 0; // 다음 칸을 채우다가 조건에 맞지 않게 되면 현재 칸을 다시 채우도록 빈칸으로 초기화
        }
    }
}

int main(void)
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];

            if (sudoku[i][j] == 0)
                blank.push_back({ i, j }); // 빈칸인 경우 배열에 넣음
        }

    dfs(0);

    return 0;
}

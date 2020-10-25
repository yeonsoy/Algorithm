#include <iostream>
using namespace std;

// 유클리드 게임

int a, b;

string EuclidGame(int big, int small, int cnt)
{
    if (big < small)
        swap(big, small);

    if (big % small == 0)
        return (cnt % 2 == 0 ? "A wins" : "B wins");

    if (big / (float)small >= 2)
        return (cnt % 2 == 0 ? "A wins" : "B wins");

    else
        return EuclidGame(big - small, small, cnt + 1);
}

int main()
{
    while (true)
    {
        cin >> a >> b;

        if (a == 0 && b == 0)
            break;

        cout << EuclidGame(a, b, 0) << endl;
    }

    return 0;
}
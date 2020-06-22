#include <iostream>
#include <math.h>
using namespace std;

// 직사각형에서 탈출

int x, y, w, h;

int main(void)
{
    cin >> x >> y >> w >> h;

    int min = 10000000;
    //(0, 0) ~ (0, 3)
    //(10,0) ~ (10,3)
    for (int i = 0; i < w; i++)
    {
        int d = sqrt(pow(x - i, 2) + pow(y, 2));
        if (min > d)
            min = d;

        d = sqrt(pow(x - i, 2) + pow(y - h, 2));
        if (min > d)
            min = d;
    }

    for (int i = 0; i < h; i++)
    {
        int d = sqrt(pow(x, 2) + pow(y - i, 2));
        if (min > d)
            min = d;

        d = sqrt(pow(x - w, 2) + pow(y - i, 2));
        if (min > d)
            min = d;
    }

    cout << min;

    return 0;
}

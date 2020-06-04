#include <iostream>

using namespace std;

// 터렛

struct pos
{
    int x;
    int y;
    int r;
};

int getCount(pos p1, pos p2)
{
    // p1의 반지름 p1.r
    // p2의 반지름 p2.r
    // 두 원은 한 점에서 만나거나 두 점에서 만난다. (한점에서 만나는 경우 안에서 내접하거나 바깥에서 외접한다.)
    // 아니면 두 원은 겹쳐있다. (일치한다)
    // 혹은 두 원은 만나지 않는다. (한 원이 다른 원 안에 있다. 혹은 아예 바깥에 있다.)
    
    int dx = p1.x - p2.x; // 두 점의 x 사이의 거리
    int dy = p1.y - p2.y; // 두 점의 y 사이의 거리
    
    int r_add = p1.r + p2.r; // 두 원의 반지름 합
    r_add *= r_add;
    int r_sub = (p1.r > p2.r) ? (p1.r - p2.r) : (p2.r - p1.r); // 두 원의 반지름 차
    r_sub *= r_sub;
    int d = dx * dx + dy * dy; // p1과 p2의 거리
     
    if(d == 0) // 두 점이 같을 때
    {
        if(p1.r == p2.r)
            return -1; // 두 원이 일치한다
        else
            return 0; // 두 원이 만나지 않는다 (한 원의 내부에 있다)
    }
    else if(d < r_add && d > r_sub) return 2; // 두 점에서 만난다
    else if(d == r_add || d == r_sub) return 1; // 두 원이 한 점에서 만난다
    else return 0;
}

int main()
{
    int t;
    cin >> t;
    
    for(int i =0; i<t; i++)
    {
        pos p1, p2;
        cin >> p1.x >> p1.y >> p1.r >> p2.x >> p2.y >> p2.r;
        cout << getCount(p1, p2) << endl;
    }
        

    return 0;
}

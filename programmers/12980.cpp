#include <iostream>
#include <math.h>
using namespace std;

// 점프와 순간 이동

int solution(int n)
{
    // n만큼 떨어져있는 장소
    // k칸 점프 (사용량 k)
    // 현재 거리 * 2 순간이동 (사용량 0)
    
    int ans = 0;
    int num = n;
    
    while(num)
    {
        int binary = num % 2;
        ans += binary;
        num /= 2;
    }

    return ans;
}

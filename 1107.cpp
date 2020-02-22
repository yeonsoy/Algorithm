#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// 리모컨
// 일부 버튼이 고장났다.
// N채널로 이동하려 할 때, 버튼을 최소 몇 번 눌러야 하는가?
// 0 ~ 9, +, -
// 현재 채널은 100번

int N, M;
vector<int> broken;

int changeFirstChannel()
{
    return abs(N - 100);
}

bool possible(int num)
{
    if (num == 0)
    {
        if (find(broken.begin(), broken.end(), 0) == broken.end())
            // 0이 망가지지 않았다면
            return true;
        else
            return false;
    }
    
    while (num) // 채널 전체의 숫자를 누를 수 있다면
    {
        if (find(broken.begin(), broken.end(), num % 10) != broken.end())
            // 입력한 숫자가 망가진 숫자라면
            return false;
        num /= 10;
    }
    return true;
}

int length(int num)
{
    int result = 0;
    
    if(num == 0)
        return 1;
    
    while (num)
    {
        num /= 10;
        result++;
    }
    
    return result;
}

int clickNumberChannel()
{
    int result = 2e9;
    int pivot = 0;

    for (int i = 0; i < 1000001; i++)
    {
        if (possible(i)) // 망가지지 않은 숫자라면
        {
            int click = abs(N - i); // + or - 버튼 클릭 횟수
            if (result > click) // 현재 클릭 횟수보다 작았다면
            {
                result = click;
                pivot = i; // 지금 숫자 저장
            }
        }
    }
    
    return result + length(pivot);
}

int main(void)
{
    cin >> N >> M;
    
    for (int i = 0; i < M; i++)
    {
        int button;
        cin >> button;
        broken.push_back(button);
    }
    
    cout << min(changeFirstChannel(), clickNumberChannel()) << endl;
    
    return 0;
    
}

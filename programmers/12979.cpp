#include <iostream>
#include <vector>
using namespace std;

// 기지국 설치

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int nowPos = 0;
    int pivot = 1;
    
    while(pivot <= n) {
        // 기지국의 위치보다는 오른쪽에 있을 때
        if(nowPos < stations.size() && pivot >= stations[nowPos] - w)
        {
            pivot = stations[nowPos] + w + 1;
            nowPos++;
        }
        else {
            pivot += 2*w+1;
            answer++;
        }
    }
    
    return answer;
}

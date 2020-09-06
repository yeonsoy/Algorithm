#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 체육복

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int lost_re = 0;
    for (int i = 0; i < lost.size(); i++)
    {
        for (int k = 0; k < reserve.size(); k++)
        {
            if (lost[i] == reserve[k])
            {
                reserve[k] = -1; // 만약 여벌의 체육복이 있는 학생이 도난 당한 경우
                lost[i] = -1;
                lost_re ++;
            }
        }
    }
    
    answer = n - lost.size() + lost_re;

    for (int i = 0; i < lost.size(); i++)
    {
        for (int k = 0; k < reserve.size(); k++)
        {
            if (abs(lost[i] - reserve[k]) == 1) // 앞 뒷번호의 학생인 경우
            {
                lost[i] = -1;
                reserve[k] = -1;
                answer++;
            }
        }
    }

    return answer;
}

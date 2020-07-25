#include <iostream>
#include <vector>
using namespace std;
 
// 수영장
// 1일 이용권 : 1일 이용 가능
// 1달 이용권 : 1달 이용 가능, 매달 1일 시작
// 3달 이용권 : 3달 이용 가능, 매달 1일 시작 (11월, 12월에도 사용 가능)
// 1년 이용권 : 1년 이용 가능, 매년 1월 1일 시작
// 이용권 사용일 수가 있는 달만 데려 와야함.

int useMonth[13];
int day, month, month3, year;
 
int answer = 0;
 
void solve(int n, int sum)
{
    if (n > 12)
    {
        answer = (sum < answer) ? sum : answer;
        return;
    }
 
    solve(n+1, sum + useMonth[n]*day);
    solve(n+1, sum + month);
    solve(n+3, sum + month3);
}
 
 
int main()
{
    int test = 0;
    cin >> test;
 
    for (int t = 0; t < test; t++)
    {
        int n = 0;
        cin >> day >> month >> month3 >> year;
 
        for (int i = 1; i <= 12; i++)
            cin >> useMonth[i];
         
        answer = year; // 연간 이용권을 사용했을 때를 기준으로 더 큰지 비교
        solve(1, 0);
 
        cout << "#" << t + 1 << " " << answer << endl;
    }
    return 0;
}

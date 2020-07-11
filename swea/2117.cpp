#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
// 홈 방범 서비스
// 운영비용은 k^2 + (k-1)^2
// 도시의 크기 N은 5 이상 20 이하
// 하나의 집이 지불할 수 있는 비용 M
// 손해를 보지 않고 서비스를 제공할 수 있는 집의 최대 수
 
// 집의 point에서 퍼져나갔을 때, (주변 집의 개수 * 비용) - 서비스 비용 > 0 이면 답으로 취급.
// 기존의 답보다 큰 경우 변경.
 
typedef pair<int, int> point;
 
int N, M;
int town[20][20];
vector <point> houses;
int answer = 0;
point dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
void solve(int k, point p)
{
    int pay = 0;
    int temp = k - 1;
    int temp2 = 0;
     
    for(int r = p.first - (k - 1); r<p.first; r++)
    {
        for(int c = p.second - (k - 1) + temp; c<=p.second + (k - 1) - temp; c++)
        {
            if(r < 0 || r >= N)
                continue;
             
            if(c < 0 || c >= N)
                continue;
             
            if(town[r][c] == 1)
                pay += M; // 방범 서비스가 제공되는 범위 내의 집이면 M만큼 비용을 냄
        }
        temp --;
    }
     
    for(int r = p.first; r<=p.first + (k - 1); r++)
    {
        for(int c = p.second - (k - 1) + temp2; c<=p.second + (k - 1) - temp2; c++)
        {
            if(r < 0 || r >= N)
                continue;
             
            if(c < 0 || c >= N)
                continue;
             
            if(town[r][c] == 1)
                pay += M; // 방범 서비스가 제공되는 범위 내의 집이면 M만큼 비용을 냄
        }
        temp2++;
    }
     
    int price = k * k + (k - 1) * (k - 1); // 방범 비용
    if(pay - price >= 0)
        answer = (answer < pay/M) ? pay/M : answer;
}
 
 
int main()
{
    int test_case;
     
    cin >> test_case;
     
    for(int t = 0; t<test_case; t++)
    {
        cin >> N >> M;
         
        for(int i =0; i<N; i++)
            for(int j =0; j<N; j++)
            {
                cin >> town[i][j];
                 
                if(town[i][j] == 1)
                    houses.push_back({i, j});
            }
         
        for(int k =1; k<=N +1; k++)
         //  for(int i = 0; i<houses.size(); i++)
            for(int i =0; i<N; i++)
                       for(int j =0; j<N; j++)
                solve(k, {i, j});
         
        cout << "#" << t+1 << " " << answer << endl;
         
        houses.clear();
        answer = 0;
    }
    return 0;
}

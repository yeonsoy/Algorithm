#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// 러시아 국기 같은 깃발
// 맨 위 한 줄 이상은 흰색
// 두 번째줄 한 줄 이상은 빨간색
// 맨 아래 한 줄 이상은 파란색
 
int T;
int N, M;
struct colors {
    int blue, white, red;
};
 
vector<colors> flag;
int answer = 987654321;
 
void check(int start, int end)
{
    int sum = 0;
    int blue = 0, white = 0, red = 0;
     
    for(int i = 0; i<N; i++)
        if(i<start)
            white += flag[i].red + flag[i].blue; // 흰색
        else if(i<end)
            blue += flag[i].white + flag[i].red; // 파란색
        else
            red += flag[i].white + flag[i].blue; // 빨간색
     
    sum = blue + white + red;
 
    answer = (answer > sum) ? sum : answer;
}
 
 
int main()
{
    cin >> T;
     
    for(int test_case = 0; test_case < T; test_case++) {
        cin >> N >> M;
         
        for(int i = 0; i<N; i++)
        {
            colors line = {0, 0, 0};
             
            string str;
            cin >> str;
             
            for(int j=0; j<M; j++)
            {
                if(str[j] == 'R') line.red++;
                else if(str[j] == 'W') line.white++;
                else if(str[j] == 'B') line.blue++;
            }
             
            flag.push_back(line);
        }
         
        for(int i = 1; i<N; i++)
            for(int j = i + 1; j<N; j++)
                check(i, j);
         
        cout << "#" << test_case + 1 << " " << answer << endl;
        answer = 987654321;
        flag.clear();
    }
    return 0;
}

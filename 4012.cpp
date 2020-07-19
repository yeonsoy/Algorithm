#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 
// 요리사
 
int T;
int N;
int synergy[17][17];
int isUsed[17];
int answer = 987654321;
 
void dfs(int idx, int count)
{
    if(count == N/2)
    {
        vector<int> foodA;
        vector<int> foodB;
         
        for(int i =0;i<N; i++)
        {
            if(isUsed[i]) foodA.push_back(i);
            else foodB.push_back(i);
        }
         
        int sa = 0;
        int sb = 0;
        for(int i = 0; i<N/2; i++)
            for(int j =0; j<N/2; j++)
            {
                sa += synergy[foodA[i]][foodA[j]];
                sb += synergy[foodB[i]][foodB[j]];
            }
         
        answer = (answer > abs(sa - sb)) ? abs(sa - sb) : answer;
         
        return;
    }
     
    for(int i = idx + 1; i<N; i++)
    {
        if(!isUsed[i]) {
            isUsed[i] = true;
            dfs(i, count+1);
            isUsed[i] = false;
        }
    }
     
}
 
int main()
{
    cin >> T;
   
     
    for(int test_case = 0; test_case < T; test_case++) {
    cin >> N;
    for(int i =0; i<N; i++)
        for(int j =0;j<N; j++)
            cin >> synergy[i][j];
     
    dfs(0, 0);
     
    cout << "#" << test_case + 1 << " " << answer << endl;
        for(int i =0; i<17; i++)
            isUsed[i] = false;
            answer = 987654321;
    }
     
 
     
    return 0;
}

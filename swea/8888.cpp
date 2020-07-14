#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// 시험

int tc;
int N, T, P;
 
int result[2001][2001];
int score[2001];
 
struct ranking {
    int score;
    int index;
    int count;
};
 
bool compare(ranking a, ranking b) // 점수 번호 개수
{
    if(a.score == b.score) // 점수가 같으면
    {
        if(a.count == b.count) // 맞은 개수가 같으면
            return a.index < b.index; // 번호가 작은 쪽
        else
            return a.count > b.count; // 맞은 개수가 많은 쪽
    }
    else
        return a.score > b.score;
}
 
int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
     
    for(int test_case = 0; test_case < tc; test_case++) {
        cin >> N >> T >> P;
         
        vector <ranking> ranks(N + 1);
        memset(result, 0, sizeof(result));
        memset(score, 0, sizeof(score));
         
        for(int i =0; i<N; i++)
        {
            for(int k = 0; k<T; k++)
            {
                cin >> result[i][k];
                if(result[i][k] == 0) score[k] ++;
            }
        }
         
        for(int i = 0; i<N; i++)
        {
            for(int k =0; k<T; k++)
            {
                if(result[i][k])
                {
                    ranks[i].score += score[k]; // 참가자가 획득한 점수
                    ranks[i].count ++; // 맞은 개수
                }
            }
            ranks[i].index = i; // 번호
        }
         
        sort(ranks.begin(), ranks.end(), compare);
         
        for(int i = 0; i<ranks.size(); i++)
            if(ranks[i].index == P - 1)
            {
                cout << "#" << test_case+1 << " " << ranks[i].score << " " <<  i + 1  << endl;
                break;
            }
    }
    return 0;
}

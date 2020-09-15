#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 예산

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    for(int i = 0; i<d.size(); i++)
    {
         budget -= d[i];
        
        if(budget >= 0)
            answer++;
        else
            break;
    }

    return answer;
}

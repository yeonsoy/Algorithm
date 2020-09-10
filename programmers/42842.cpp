#include <string>
#include <vector>
using namespace std;

// 카펫

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int r = 3; r <=yellow + 2; r++)
        for(int c = 3; c <=(brown - 6) / 2 + 2; c++)
        {
            if(c < r) continue;
            if(r * c == brown + yellow)
                if((r - 2) * (c - 2) == yellow)
                {
                    answer.push_back(c);
                    answer.push_back(r);
                    return answer;
                }
        }
    
    return answer;
}

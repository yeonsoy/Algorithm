#include <string>
using namespace std;

// 다트 게임

int solution(string dartResult) {
    int answer = 0;
    int idx = 0;
    int score[3];
    string temp = "";
    
    for(int i = 0; i<dartResult.size(); i++) {
        if(dartResult[i] >= '0' && dartResult[i] <= '9')
            temp += dartResult[i];
        else {
            int cur = 0;
            if(temp.size() > 0)
                cur = stoi(temp);
            
            if(dartResult[i] == 'S')
                score[idx++] = cur;
            else if(dartResult[i] == 'D')
                score[idx++] = cur * cur;
            else if(dartResult[i] == 'T')
                score[idx++] = cur * cur * cur;
            else if(dartResult[i] == '*') {
                for(int j = idx - 2; j<idx; j++)
                    if(j >= 0)
                        score[j] *= 2;
            }
            else if(dartResult[i] == '#')
                score[idx - 1] *= -1;
            
            temp = "";
        }
    }
    
    for(int i = 0; i<3; i++)
        answer += score[i];
    
    return answer;
}

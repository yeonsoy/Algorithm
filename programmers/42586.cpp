#include <string>
#include <vector>
using namespace std;

// 기능개발

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<float> delay;
    
    for (int i = 0; i < progresses.size(); i++)
        delay.push_back((100 - progresses[i]) / (float)speeds[i]);
    
    int k = 1;
    float next = delay.at(0);
    
    for (int i = 1; i < delay.size(); i++)
    {
        if ((int)(next + 0.9) >= (int)(delay.at(i) + 0.9))
            k++;
        else
        {
            answer.push_back(k);
            k = 1;
            next = delay.at(i);
        }
        
        if (i == delay.size() - 1)
            answer.push_back(k);
    }
    
    return answer;
}

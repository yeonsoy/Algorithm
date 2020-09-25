#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 제일 작은 수 제거하기

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    else
    {
        for(int i = 0; i<arr.size(); i++)
            answer.push_back(arr[i]);
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    for(int i = 0; i<answer.size(); i++)
    {
        if(answer[i] == arr[arr.size()-1])
            answer.erase(answer.begin() + i);
    }
    return answer;
}

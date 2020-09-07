#include <vector>
#include <iostream>
using namespace std;

// 같은 숫자는 싫어

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    
    for(int i =0; i<arr.size(); i++)
    {
        if(i == 0)
            answer.push_back(arr[i]);
        else if(arr[i-1] == arr[i])
            continue;
        else
            answer.push_back(arr[i]);
    }
    
    return answer;
}

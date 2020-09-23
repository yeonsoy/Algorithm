#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 두 개 뽑아서 더하기

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i = 0; i<numbers.size(); i++)
        for(int j = i + 1; j<numbers.size(); j++)
            answer.push_back(numbers[i] + numbers[j]);
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()),answer.end());

    
    return answer;
}

#include <string>
#include <vector>
using namespace std;

// 타겟 넘버

int answer = 0;
bool isUsed[51];

void solve(int idx, int sum, int target, vector<int> numbers) {
    
    if(idx == numbers.size()) {
        
        if(sum == target)
            answer++;
        
        return;
    }
    
    solve(idx + 1, sum + numbers[idx], target, numbers);
    solve(idx + 1, sum - numbers[idx], target, numbers);
}

int solution(vector<int> numbers, int target) {
    solve(0, 0, target, numbers);
    return answer;
}

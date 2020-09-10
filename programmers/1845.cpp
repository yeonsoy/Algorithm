#include <vector>
#include <set>
using namespace std;

// 폰켓몬

int solution(vector<int> nums)
{
    int answer = 0;
    set <int> ponketmon(nums.begin(), nums.end());
    
    if(ponketmon.size() >= nums.size() / 2)
        answer = nums.size() / 2;
    else
        answer = ponketmon.size();
    
    return answer;
}

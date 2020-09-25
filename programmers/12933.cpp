#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

// 정수 내림차순으로 배치하기

long long solution(long long n) {
    
    long long answer = 0;
    vector <long long> nums;
    long long temp = n;
    while(temp)
    {
        long long k = temp % 10;
        nums.push_back(k);
        temp = temp / 10;
    }
    
    sort(nums.begin(), nums.end());
        
    for(int i =0; i<nums.size(); i++)
        answer += nums[i] * pow(10, i);

    return answer;
}

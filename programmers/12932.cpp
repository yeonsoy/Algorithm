#include <string>
#include <vector>
using namespace std;

// 자연수 뒤집어 배열로 만들기

vector<int> solution(long long n) {
    vector<int> answer;
    
    long long temp = n;
    
    while(temp) {
        answer.push_back(temp % 10);
        temp /= 10;
    }
    
    return answer;
}

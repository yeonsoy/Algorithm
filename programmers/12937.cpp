#include <string>
#include <vector>
using namespace std;

// 짝수와 홀수

string solution(int num) {
    string answer = "Odd";
    
    if(num % 2 == 0)
        answer = "Even";
    
    return answer;
}

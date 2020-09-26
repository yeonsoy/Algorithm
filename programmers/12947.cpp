#include <string>
#include <vector>
using namespace std;

// 하샤드 수

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int n = x;
    
    while(n)
    {
        sum += n % 10;
        n = n / 10;
    }
    
    answer = (x % sum == 0);
    
    return answer;
}

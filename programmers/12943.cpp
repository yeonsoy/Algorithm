#include <string>
#include <vector>
using namespace std;

// 콜라츠 추측

int solution(int num) {
    int answer = 0;
    long long int n = num;
    
    while (n != 1)
    {
        answer++;
        
        if(n % 2 == 0)
            n = n / 2;
        else
            n = n * 3 + 1;
        
        if(answer >= 500)
            return -1;
    }
    return answer;
}

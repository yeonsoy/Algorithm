#include <string>
#include <vector>
using namespace std;

// 3진법 뒤집기

int solution(int n) {
    int answer = 0;
    string str = "";
    
    while(n)
    {
        str += to_string(n % 3);
        n /= 3;
    }
    
    int idx = 1;
    for(int i = str.size() - 1; i >= 0; i--)
    {
        answer += (str[i] - '0') * idx;
        idx *= 3;
    }

    return answer;
}

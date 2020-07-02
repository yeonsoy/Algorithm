#include <iostream>
#include <algorithm>
using namespace std;

// 큰 수 A+B

string a, b;
string answer;
int tens;

int main() {
    
    cin >> a >> b;
    
    int a_len = a.size() - 1;
    int b_len = b.size() - 1;
    
    while(true) {
        
        int a_num = 0;
        int b_num = 0;
        
        if(a_len >= 0)
            a_num = a[a_len--] - '0';
        if(b_len >= 0)
            b_num = b[b_len--] - '0';
        
        
        int res = a_num + b_num + tens;
        if(res >= 0 && res < 10) {
            answer.push_back(res + '0');
            tens = 0;
        }
        else if(res >= 10){
            res %= 10;
            answer.push_back(res + '0');
            tens = 1;
        }
        
        if(a_len == -1 && b_len == -1)
            break;
    }
    
    if(tens == 1)
        answer.push_back(1 + '0');
    
    reverse(answer.begin(), answer.end());
    
    for(int i = 0; i<answer.size(); i++)
        cout << answer[i];
    
    return 0;
}

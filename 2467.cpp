#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 용액

int N;
long long a, b;
long long answer = 2e9;
vector <long long> number;

int main() {
    
    fastio();
    
    cin >> N;
    
    number.resize(N);
    for(int i = 0; i<N; i++)
        cin >> number[i];
    
    int st = 0;
    int ed = N - 1;
    
    while(st < ed) {
        
        if(abs(number[st] + number[ed]) < answer)
        {
            answer = abs(number[st] + number[ed]);
            
            a = number[st];
            b = number[ed];
        }
        
        // 둘의 합이 음수인 경우에는 산성용액이 알카리쪽으로, 반대인 경우엔 알카리용액이 산성쪽으로
        if(number[st] + number[ed] < 0) st++;
        else ed--;
        
    }
    
    cout << a << " " << b << "\n";
    
    
    return 0;
}

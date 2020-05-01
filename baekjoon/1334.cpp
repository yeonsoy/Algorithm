#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 다음 팰린드롬 수

string N;

void plusTens(string &num, int idx) {
    
    num[idx]++;
    
    for(int i = idx; i>0; i--)
        if(num[i] > '9') {
            num[i] = '0';
            num[i - 1]++;
        }
    
    if(num[0] > '9') {
        num.insert(num.begin(), '1');
        num[1] = '0';
    }
}

void makePalindrome(string num) {
    
    plusTens(num, num.size() - 1);
    
    for(int i = 0; i < num.size() / 2; i++)
        if(num[i] != num[num.size() - i - 1])
            if(num[i] < num[num.size() - i - 1])
                plusTens(num, num.size() - i - 2);
    
    
    for(int i = 0; i < num.size() / 2; i++)
        if(num[i] != num[num.size() - i - 1])
            num[num.size() - i - 1] = num[i];
    
    for(int i = 0; i < num.size(); i++)
        cout << num[i];
    
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    makePalindrome(N);
    
    return 0;
}

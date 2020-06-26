#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 암호 만들기

int L, C;
vector <char> password;
vector <string> answers;
bool isUsed[16];
char alphabet[] = {'a', 'e', 'i', 'o', 'u'};

bool isPossible(string str) {
    
    int a = 0, b = 0;
    for(int i = 0; i<str.size(); i++) {
        bool flag = false;
        for(int j = 0; j<5; j++)
            if(str[i] == alphabet[j]) {
                flag = true;
                break;
            }
        if(flag) a++;
        else b++;
        
        if(a > 0 && b >= 2)
            return true;
    }
    
    return false;
}

void solve(int idx, string str) {
    
    if(str.size() == L)
    {
        if(isPossible(str))
            answers.push_back(str);
        return;
    }
    
    for(int i = idx; i<password.size(); i++) {
        if(!isUsed[i]) {
            isUsed[i] = true;
            solve(i, str + password[i]);
            isUsed[i] = false;
        }
    }
    
}

int main() {
    
    fastio();
    
    cin >> L >> C;
    
    for(int i = 0; i<C; i++) {
        char ch;
        cin >> ch;
        password.push_back(ch);
    }
    
    sort(password.begin(), password.end());
    
    solve(0, "");
    
    sort(answers.begin(), answers.end());
    answers.erase(unique(answers.begin(), answers.end()), answers.end());
    
    for(int i = 0; i<answers.size(); i++)
        cout << answers[i] << endl;
    
    return 0;
}

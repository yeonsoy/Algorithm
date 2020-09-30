#include <iostream>
#include <vector>
using namespace std;

// 부분 문자열

string P, S;

vector<int> getPi(string p)
{
    int idx = 0;
    vector<int> pi(p.size(), 0);
    for(int i = 1; i < p.size() ; i++)
    {
        while(idx > 0 && p[i] != p[idx])
            idx = pi[idx - 1];
        if(p[i] == p[idx])
            pi[i] = ++idx;
    }
    
    return pi;
}

bool kmp(string s, string p)
{
    auto pi = getPi(p);
    
    int idx = 0;
    
    for(int i = 0 ; i < s.size() ; i++)
    {
        while(idx > 0 && s[i] != p[idx])
            idx = pi[idx - 1];
        if(s[i] == p[idx])
        {
            if(idx == p.size()-1)
                return true;
            else idx++;
        }
    }
    return false;
}

int main() {
    
    cin >> P >> S;
    
    cout << kmp(P, S);
    
    return 0;
}

#include <string>
#include <vector>
using namespace std;

// 괄호 변환

bool isPossible(string p){
    int res = 0;
    
    for(int i = 0; i<p.size(); i++)
    {
        if(p[i] == '(')
            res++;
        else 
        {
            res--;
            if(res < 0)
                return false;
        }
    }
    
    return true;
}

string makeCorrect(string p) {
    if(p == "")
        return p;
    
    string u = "", v = "";
    int l = 0, r = 0;
    
    for(int i = 0; i<p.size(); i++)
    {
        if(p[i] == '(')
            l++;
        else
            r++;
        
        if(l == r) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    
    if(isPossible(u))
        return u + makeCorrect(v);
    else 
    {
        string w = "(";
        w += makeCorrect(v) + ")";
        u = u.substr(1, u.size() - 2);
        
        for(int i = 0; i<u.size(); i++)
        {
            if(u[i] == '(')
                w += ')';
            else
                w += '(';
        }
        
        return w;
    }
}

string solution(string p) {
    if(isPossible(p))
        return p;
    return makeCorrect(p);
}
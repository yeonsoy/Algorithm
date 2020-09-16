#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 문자열 내 마음대로 정렬하기

int n;

int strlen(string s)
{
    int len = 0;
    for(int i = 0; i<s[i]; i++)
        len ++;
    return len;
}

bool compare(string a, string b)
{
    if(a[n] > b[n])
        return false;
    else if (a[n] < b[n])
        return true;
    else
    {
        for(int i = 0; i<(strlen(a) < strlen(b) ? a[i] : b[i]); i++)
        {
            if(a[i] > b[i])
                return false;
            else if(a[i] < b[i])
                return true;
        }
    }
    
    return false;
}

vector<string> solution(vector<string> strings, int k) {
    vector<string> answer;
    
    n = k;
    
    sort(strings.begin(), strings.end(), compare);
    answer = strings;
    return answer;
}

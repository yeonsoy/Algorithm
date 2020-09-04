#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 비밀지도

string convertBinary(int n, int len) {
    
    string res = "";
    
    for(int i = 0; i<len; i++)
        res += ' ';
    
    int idx = len - 1;
     while(n > 0){
        if(n % 2 == 1)
            res[idx] = '#';
        else
            res[idx] = ' ';

        n /= 2;
        idx--;
    }
    
    return res;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i<n; i++) {
        int res = (arr1[i] | arr2[i]);
        string temp = convertBinary(res, n);
        
        answer.push_back(temp);
    }
    
    return answer;
}

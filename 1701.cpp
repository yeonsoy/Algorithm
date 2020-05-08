#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Cubeditor

// KMP 알고리즘

string str;
vector <string> suf;
int answer;

int main() {
    
    cin >> str;
    
    for (int i = 0; i < str.size(); i++) {
        suf.push_back(str.c_str() + i);
        cout << suf[i] << endl;
    }
    sort(suf.begin(), suf.end());
    
    int j = 0;
    
    for (int i = 0; i < suf.size() - 1; i++) {
        while (suf[i][j] == suf[i + 1][j])
            j++;
        
        answer = max(answer, j);
        j = 0;
    }
    
    cout << answer << endl;
    
    return 0;
}

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// 민정이와 광직이의 알파벳 공부 

int N;
int TC;
int answer;
vector <string> word;
bool isUsed[16];
int alphabet[27];
 
bool checkAlphabet() {
     
    for(int i = 0; i<26; i++)
        if(alphabet[i] < 1)
            return false;
      
    return true;
}
 
void checkSet(int idx) {
     
    if(checkAlphabet()) {
        answer++;
    }
     
    for(int i = idx; i<word.size(); i++)
    {
        if(!isUsed[i]) {
            for(int j = 0; j<word[i].size(); j++)
                alphabet[word[i][j] - 'a']++;
             
            isUsed[i] = true;
             
            checkSet(i);
             
            for(int j = 0; j<word[i].size(); j++)
                alphabet[word[i][j] - 'a']--;
            isUsed[i] = false;
        }
    }
     
}
 
int main () {
     
    cin >> TC;
     
    for(int test_case = 0; test_case < TC; test_case++) {
         
        cin >> N;
         
         
        for(int i = 0; i<N; i++)
        {
            string str;
            cin >> str;
            word.push_back(str);
        }
         
        checkSet(0);
         
        cout << "#" << test_case + 1 << " " << answer << endl;
         
        answer = 0;
        word.clear();
        memset(isUsed, false, sizeof(isUsed));
        memset(alphabet, 0, sizeof(alphabet));
    }
     
    return 0;
}

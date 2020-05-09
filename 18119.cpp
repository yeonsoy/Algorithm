#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 단어 암기

int N, M;
int words[10000][26];
int alphabet[10000];
int origin[10000];

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    string str;
    for(int i = 0; i<N; i++) {
        cin >> str;
        
        for(int j = 0; j<str.size(); j++)
            words[i][str[j] - 'a'] = 1;
        
        for(int j = 0; j<26; j++)
            if(words[i][j]) {
                alphabet[i]++; // 포함한 알파벳 개수
                origin[i]++;
            }
    }
    
    int flag;
    char ch;
    int answer = N;
    
    for(int i = 0; i<M; i++) {
        cin >> flag >> ch;

        // 까먹는 경우
        if(flag == 1) {
            for(int j = 0; j<N; j++)
                if(words[j][ch - 'a'] == 1) { // 갖고 있던 알파벳인 경우에
                    words[j][ch - 'a'] = -1;
                    alphabet[j]--;
                    if(alphabet[j] + 1 == origin[j]) // 기존 알파벳 개수와 같다면
                        answer--;
                }
        }
        // 기억해낸 경우
        else {
            for(int j = 0; j<N; j++)
                if(words[j][ch - 'a'] == -1) { // 까먹고 있던 알파벳인 경우에
                    words[j][ch - 'a'] = 1;
                    alphabet[j]++;
                    if(alphabet[j] == origin[j])
                        answer++;
                }
        }
        
        cout << answer << endl;
    }
    
    return 0;
}

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 단어 변환

bool isPossible(string st, string ed) {
    
    int n = 0;
    for(int i = 0; i<st.size(); i++) {
        if(st[i] != ed[i])
            n++;
        if(n > 1) return false;
    }
    
    return true;
}

int solution(string begin, string target, vector<string> words) {
    
    bool flag = false;
    
    for(int i = 0; i<words.size(); i++)
        if(target == words[i])
            flag = true;
    
    if(!flag)
        return 0; // 만들 수 없다면 처음부터 0 리턴
    
    bool visited[51];
    memset(visited, false, sizeof(visited));
    
    queue <pair<string, int>> que;
    for(int i = 0; i<words.size(); i++) {
        if(isPossible(begin, words[i])) {
            que.push({words[i], 1});
            visited[i] = true;
        }
    }
    
    while(!que.empty()) {
        string st = que.front().first;
        int n = que.front().second;
        que.pop();
        
        for(int i = 0; i<words.size(); i++)
        {
            if(isPossible(st, words[i]) && !visited[i]) {
                que.push({words[i], n + 1});
                visited[i] = true;
            }
        }
        
        if(st == target)
            return n;
    }
}

int main() {
    
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
    
    return 0;
}

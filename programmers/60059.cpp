#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 자물쇠와 열쇠

void rotateKey(vector<vector<int>> &key) {
    
    vector<vector<int>> temp(key);
    
    for(int i = 0; i < key.size(); i++)
        for(int j = 0; j< key.size(); j++)
            temp[i][j] = key[j][key.size() - i - 1];
    
    key = temp;
}

bool checkKey(int r, int c, int n, vector<vector<int>> key, vector<vector<int>> map) {
    
    for(int i = r; i<r + key.size(); i++)
        for(int j = c; j<c + key.size(); j++)
            map[i][j] += key[i - r][j - c];
    
    for(int i = key.size() - 1; i<n + key.size() - 1; i++)
        for(int j = key.size() - 1; j<n + key.size() - 1; j++)
            if(map[i][j] != 1) return false;
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int N = int(lock.size() + (key.size() - 1) * 2);
    
    vector<vector<int>>map (N, vector<int>(N, 0));
    
    for(int i = key.size() - 1; i<lock.size() + key.size() - 1; i++)
        for(int j = key.size() - 1; j<lock.size() + key.size() - 1; j++)
            map[i][j] = lock[i - (key.size() - 1)][j - (key.size() - 1)];
    
    for(int i = 0; i<4; i++) {
        
        for(int j = 0; j<N - (key.size() - 1); j++)
            for(int k = 0; k<N - (key.size() - 1); k++)
                if(checkKey(j, k, lock.size(), key, map))
                    return true;
        
        rotateKey(key);
    }
    
    return answer;
}

int main () {
    
    cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 격자판의 숫자 이어 붙이기

typedef pair<int, int> point;
int T;
int map[4][4];
vector <string> numbers;

void checkPossible(int r, int c, string s) {
    
    if(r < 0 || r >= 4 || c < 0 || c >= 4) return;
    if(s.size() == 7) {
        numbers.push_back(s);
        return;
    }
    
    checkPossible(r + 1, c, s + to_string(map[r][c]));
    checkPossible(r, c + 1, s + to_string(map[r][c]));
    checkPossible(r - 1, c, s + to_string(map[r][c]));
    checkPossible(r, c - 1, s + to_string(map[r][c]));
    
}

int main() {
    
    fastio();
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        
        for(int i = 0; i<4; i++)
            for(int j = 0; j<4; j++)
                cin >> map[i][j];
        
        
        for(int i = 0; i<4; i++)
            for(int j = 0; j<4; j++)
                checkPossible(i, j, "");
        
        sort(numbers.begin(), numbers.end());
        numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
        
        cout << "#" << test_case + 1 << " " << numbers.size() << "\n";
        
        numbers.clear();
    }
    
    return 0;
}

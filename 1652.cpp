#include <iostream>
using namespace std;

// 누울 자리를 찾아라

int N;
int answer;
char map[101][101];

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin >> map[i][j];
    
    for(int i = 0; i<N; i++) {
        bool flag = false;
        for(int j = 0; j<N - 1; j++) {
            if(!flag && map[i][j] == '.' && map[i][j + 1] == '.') {
                answer++;
                flag = true;
            }
            if(map[i][j] == 'X')
                flag = false;
        }
    }
    cout << answer << " ";
    answer = 0;
    for(int i = 0; i<N; i++) {
        bool flag = false;
        for(int j = 0; j<N - 1; j++) {
            if(!flag && map[j][i] == '.' && map[j + 1][i] == '.') {
                answer++;
                flag = true;
            }
            if(map[j][i] == 'X')
                flag = false;
        }
    }
    
    cout << answer << endl;
    
    
    return 0;
}

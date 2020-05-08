#include <iostream>
#include <vector>
using namespace std;

// 용감한 용사 진수

int N, K;
int soldier[101][3];
int answer = 2e9;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> soldier[i][j];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                int count = 0;
                for (int jinsu = 0; jinsu < N; jinsu++) {
                    // 만약 이길 수 있는 경우에
                    if (soldier[i][0] >= soldier[jinsu][0] && soldier[j][1] >= soldier[jinsu][1] && soldier[k][2] >= soldier[jinsu][2])
                        count++;
                }
                if (count >= K)
                    answer = min(answer, soldier[i][0] + soldier[j][1] + soldier[k][2]);
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}

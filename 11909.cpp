#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 배열 탈출

int n;
int arr[2223][2223];
int dp[2223][2223];
int answer = 2e9;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            dp[i][j] = 2e9;
        }
    
    int diff = 0;
    dp[1][1] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == n && j == n)
                break;
            if (i != n) {
                if (arr[i + 1][j] >= arr[i][j]) {
                    diff = arr[i + 1][j] - arr[i][j] + 1;
                    dp[i + 1][j] = min(dp[i + 1][j], diff + dp[i][j]);
                }
                else
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
            if (j != n) {
                if (arr[i][j + 1] >= arr[i][j]) {
                    diff = arr[i][j + 1] - arr[i][j] + 1;
                    dp[i][j + 1] = min(dp[i][j + 1], diff + dp[i][j]);
                }
                else
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    
    cout << dp[n][n] << endl;
    
    return 0;
}

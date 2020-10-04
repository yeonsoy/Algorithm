#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// 함께 블록 쌓기

int N, M, H;
vector <vector<int>> blocks;
int dp[51][1001];
int answer;

int main() {
    
    cin >> N >> M >> H;
    
    getchar();
    
    blocks.resize(N);
    
    for(int i = 0; i<N; i++) {
        string str;
        getline(cin, str);
        istringstream ss(str);
        string stringBuffer;
        while (getline(ss, stringBuffer, ' '))
            blocks[i].push_back(stoi(stringBuffer));
        
        // 아무 것도 선택하지 않은 경우 0
        blocks[i].push_back(0);
    }
    
    // 처음 사람으로 만들 수 있는 조합
    for(int i = 0; i<blocks[0].size(); i++)
        dp[0][blocks[0][i]] = 1;

    for(int i = 1; i<N; i++)
        for(int j = 0; j<blocks[i].size(); j++)
            for(int k = 0; k + blocks[i][j] <= H; k++)
                dp[i][k + blocks[i][j]] = (dp[i][k + blocks[i][j]] + dp[i - 1][k]) % 10007;

    answer = dp[N - 1][H];
    
    cout << answer;
    
    return 0;
}

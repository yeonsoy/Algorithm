#include <iostream>
#include <map>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 공통 부분 문자열

string a, b;
int LCS[4001][4001];
int answer;

int main() {
    
    cin >> a >> b;
    
    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
            if (a[i - 1] == b[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                if (answer < LCS[i][j])
                    answer = LCS[i][j];
             }

    cout << answer << "\n";
    
    return 0;
}

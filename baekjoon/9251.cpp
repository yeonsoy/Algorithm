#include <iostream>
#include <map>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// LCS

string a, b;
int LCS[1001][1001];
int answer;

int main() {

    fastio();

    cin >> a >> b;

    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
            if (a[i - 1] == b[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);

    cout << LCS[a.size()][b.size()] << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 땅따먹기

int max(vector <int> row) {
    
    sort(row.begin(), row.end());
    
    return row[3];
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    for(int i = 0; i<land.size() - 1; i++) {
        land[i + 1][0] += max({land[i][1], land[i][2], land[i][3]});
        land[i + 1][1] += max({land[i][0], land[i][2], land[i][3]});
        land[i + 1][2] += max({land[i][0], land[i][1], land[i][3]});
        land[i + 1][3] += max({land[i][0], land[i][1], land[i][2]});
    }
    
    answer = max(land[land.size() - 1]);
    
    return answer;
}


int main() {
    
    cout << solution({{1,2,3,5}, {5,6,7,8}, {4,3,2,1}});
    
    return 0;
}

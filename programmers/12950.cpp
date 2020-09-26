#include <string>
#include <vector>
using namespace std;

// 행렬의 덧셈

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i = 0; i<arr1.size(); i++)
    {
        vector<int> add;
        for(int k = 0; k<arr1[i].size(); k++)
            add.push_back(arr1[i][k] + arr2[i][k]);
        
        answer.push_back(add);
        add.clear();
    }
    return answer;
}

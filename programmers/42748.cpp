#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// K번째수

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector <int> split_arr;
    
    for (int i = 0; i < commands.size(); i++)
    {
        split_arr.clear();
        for (int k = commands[i][0] - 1; k < commands[i][1]; k++)
            split_arr.push_back(array[k]);
        
        sort(split_arr.begin(), split_arr.end());

        answer.push_back(split_arr[commands[i][2] - 1]);

    }
    return answer;
}

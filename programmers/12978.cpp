#include <iostream>
#include <vector>
using namespace std;

// 배달

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<int> town(N + 1, 999999);
    
    town[1] = 0;
    for(int k = 0; k < N; k++)
        for(int i = 1; i < N + 1; i++)
            for(int j = 0; j < road.size(); j++)
            {
                if(road[j][0] == i)
                    town[road[j][1]] = min(town[road[j][1]], town[i] + road[j][2]);
                else if(road[j][1] == i)
                    town[road[j][0]] = min(town[road[j][0]], town[i] + road[j][2]);
            }
    
    for(int i = 1; i < town.size(); i++)
        if(K >= town[i])
            answer++;
    
    return answer;
}

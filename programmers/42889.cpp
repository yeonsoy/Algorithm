#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 실패율

bool compare(pair<double, int> a, pair<double, int> b) {

    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map <int, int> m1, m2;
    
    for(int i = 1; i<=N; i++)
        m1[i] = 0;
    
    for(int i = 0; i<stages.size(); i++) {
        for(int j = 1; j<=stages[i]; j++)
                m1[j]++;
        
        m2[stages[i]]++;
    }
    
    map <int, int>::iterator iter;
    vector <pair<double, int>> check;
    
    for(iter = m1.begin(); iter != m1.end(); iter++)
    {
        if(iter->second != 0)
            check.push_back({m2[iter->first]/(double)iter->second, iter->first});
        else
            check.push_back({0, iter->first});
    }
    
    sort(check.begin(), check.end(), compare);
    
    for(int i = 0; i<check.size(); i++) {
        if(check[i].second <= N)
        answer.push_back(check[i].second);
    }
    
    return answer;
}

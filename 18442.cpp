#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// 우체국 1

int V, P;
long long L;
vector <long long> town;
vector <long long> answer;
vector <long long> post;
bool isUsed[21];
long long dist = LLONG_MAX;

void solve(int idx, int count) {
    
    if(count == P) {
        
        long long sum = 0;
        for (int i = 0; i < V; i++) {
            long long d = LLONG_MAX;
            for (int j = 0; j < V; j++)
                if(isUsed[j])
                    d = min(d, min(abs(town[i] - town[j]), L - abs(town[i] - town[j])));
            
            sum += d;
        }
        
        if(dist > sum)
        {
            answer.clear();
            dist = sum;
            for (int i = 0; i < V; i++)
                if(isUsed[i]) answer.push_back(town[i]);
        }
        
        return;
    }
    
    for(int i = idx; i<V; i++) {
        if(!isUsed[i]) {
            isUsed[i] = true;
            post.push_back(town[i]);
            solve(i, count + 1);
            isUsed[i] = false;
            post.pop_back();
        }
    }
    
}


int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> P >> L;
    
    long long temp;
    for(int i = 0; i<V; i++)
    {
        cin >> temp;
        town.push_back(temp);
    }
    
    sort(town.begin(), town.end());
    
    solve(0, 0);
    
    cout << dist << endl;
    
    for(int i = 0; i<answer.size(); i++)
        cout << answer[i] << " ";
    
    return 0;
    
}

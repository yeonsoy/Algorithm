#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 탑

int N;
stack<pair<int, int>> tower;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int first_tower;
    cin >> first_tower;
    tower.push({first_tower, 1});
    
    string answer = "0 ";
    
    for(int i = 2; i<=N; i++) {
        int cur_tower;
        cin >> cur_tower;
        
        while(!tower.empty()) {
            auto next_tower = tower.top();
            if(cur_tower < next_tower.first) {
                answer += to_string(next_tower.second) + " ";
                break;
            }
            tower.pop();
        }
        
        if(tower.empty()) answer += "0 ";
        
        tower.push({cur_tower, i});
    }
   
    cout << answer << endl;
    return 0;
}

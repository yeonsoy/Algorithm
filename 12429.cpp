#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 생존자 (Small)

typedef pair<int, int> food;
int T;
int N;
int answer;
vector <food> foods;
bool isUsed[101];

bool compare(food a, food b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void solve(int day) {
    
    answer = max(day, answer);
    
    for(int i = 0; i<foods.size(); i++) {
        
        if(!isUsed[i] && foods[i].first >= day) {
            isUsed[i] = true;
            // 허기를 참을 수 있는 기간만큼 아무 것도 먹지 않는다
            solve(day + foods[i].second);
            isUsed[i] = false;
        }
    }
}


int main() {
    
    fastio();
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        cin >> N;
        
        food temp;
        for(int i = 0; i<N; i++) {
            cin >> temp.first >> temp.second;
            foods.push_back(temp);
        }
        
        sort(foods.begin(), foods.end(), compare);
        
        solve(0);
        
        cout << "Case #" << test_case + 1 << ": " << answer << endl;
        
        foods.clear();
        answer = 0;
        memset(isUsed, false, sizeof(isUsed));
    }
    
    return 0;
}

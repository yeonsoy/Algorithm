#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 생존자 (Large)

typedef pair<int, int> food;
int T;
int N;
int answer;
vector <food> foods;
bool day[200004];

bool compare(food a, food b) {
    return a.first + a.second < b.first + b.second;
}

int main() {
    
    fastio();
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        cin >> N;
        
        foods.resize(N);
        for(int i = 0; i<N; i++)
            cin >> foods[i].first >> foods[i].second;
        
        sort(foods.begin(), foods.end(), compare);
        
        day[0] = true;
        
        for(int i = 0; i<N; i++)
            for(int j = foods[i].first; j>= 0; j--)
                if(day[j]) {
                    day[j + foods[i].second] = true; // 해당 음식을 먹었을 때
                    answer = max(answer, j + foods[i].second);
                }
        
        cout << "Case #" << test_case + 1 << ": " << answer << endl;
        
        foods.clear();
        answer = 0;
        memset(day, false, sizeof(day));
    }
    
    return 0;
}

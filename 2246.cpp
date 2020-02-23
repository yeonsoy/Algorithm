#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 콘도 선정
// X보다 바닷가에 더 가까운 콘도들은 모두 X보다 숙박비가 더 비싸다
// X보다 숙박비가 더 싼 콘도들은 모두 X보다 바닷가에서 더 멀다

int N;
typedef pair<int, int> condo;
vector <condo> condos;

bool dist(condo a, condo b) {
    return a.first > b.first;
}

int main() {
    
    cin >> N;
    
    for(int i =0; i<N; i++) {
        int d, c;
        cin >> d >> c;
        condos.push_back({d, c});
    }
    
    sort(condos.begin(), condos.end(), dist); // 거리 순으로 내림차순 정렬
    
    int answer = 0;
    for(int i =0; i<N; i++) {
        bool flag = false;
        for(int j =0; j<N; j++) {
            if(j == i) continue;
            if(condos[i].first >= condos[j].first && // X보다 바닷가에 더 가까운 콘도인데
               condos[i].second >= condos[j].second ) // 숙박비가 더 쌀 때
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            answer++;
    }
    
    cout << answer;
    
    return 0;
}

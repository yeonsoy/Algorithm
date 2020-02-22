#include <iostream>
#include <queue>
using namespace std;

// 계란으로 계란치기

struct egg {
    int durability;
    int weight;
};

int N;
int answer;
vector <egg> eggs;

void solve(int idx, int count) {
    
    if(idx == eggs.size()) {
        answer = (answer < count) ? count : answer;
        return ;
    }
    
    if(eggs[idx].durability <= 0) return solve(idx + 1, count); // 현재 계란이 이미 깨져있으면
    
    for(int i = 0; i<eggs.size(); i++) {
        if(i == idx) continue; // 동일한 계란이면
        if(eggs[i].durability <= 0) continue;// 이미 깨져있는 계란이면
        
        eggs[i].durability -= eggs[idx].weight;
        eggs[idx].durability -= eggs[i].weight;
        
        int temp_cnt = 0;
        if(eggs[idx].durability <= 0) temp_cnt++; // 동일한 계란이면
        if(eggs[i].durability <= 0) temp_cnt++;// 이미 깨져있는 계란이면
        
        solve(idx + 1, count + temp_cnt);
        
        eggs[i].durability += eggs[idx].weight;
        eggs[idx].durability += eggs[i].weight;
    }
    
    answer = (answer < count) ? count : answer;
}

int main()
{
    cin >> N;
    
    for(int i = 0; i<N; i++) {
        egg temp;
        cin >> temp.durability >> temp.weight;
        eggs.push_back(temp);
    }
    
    solve(0, 0);
    
    cout << answer;
    
    return 0;
}

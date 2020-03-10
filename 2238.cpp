#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 경매
struct auction {
    string S;
    int P;
    int idx;
};

int U, N;
int cnt[10001];
vector <auction> users;

bool compare(auction a, auction b) {
    
    if(cnt[a.P] == cnt[b.P]) { // 경매 금액이 나온 횟수가 같다면
        if(a.P == b.P) // 경매 금액이 같다면
            return a.idx < b.idx; // 순서가 먼저인 수
        else
            return a.P < b.P;
    }
    else
        return cnt[a.P] < cnt[b.P];
}

int main() {
    
    cin >> U >> N;
    
    for(int i = 0; i<N; i++) {
        auction temp;
        cin >> temp.S >> temp.P;
        temp.idx = i;
        cnt[temp.P]++;
        users.push_back(temp);
    }
    
    sort(users.begin(), users.end(), compare);
    
    cout << users[0].S << " " << users[0].P << endl;
    
    return 0;
}

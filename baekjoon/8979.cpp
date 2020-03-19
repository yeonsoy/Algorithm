#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 올림픽

// 국가 번호, 금 은 동 순서로 입력

struct country {
    int index;
    int gold;
    int silver;
    int bronze;
};

int N, K;
vector <country> countries;

bool compare(country a, country b) {
    
    if(a.gold == b.gold) {
        if(a.silver == b.silver) {
            if(a.bronze == b.bronze)
                return a.index == K;
            else
                return a.bronze > b.bronze;
        }
        else
            return a.silver > b.silver;
    }
    else
        return a.gold > b.gold;
    
}

int main () {
    
    cin >> N >> K;
    
    for(int i = 0; i<N; i++) {
        country c;
        cin >> c.index >> c.gold >> c.silver >> c.bronze;
        countries.push_back(c);
    }
    
    sort(countries.begin(), countries.end(), compare);

    for(int i = 0; i<countries.size(); i++) {
        
        if(countries[i].index == K)
        {
            cout << i + 1;
            break;
        }
    }
    
    return 0;
}

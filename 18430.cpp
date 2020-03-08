#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct boo_type {
    int dir; // 1, 2, 3, 4
    pair<int, int> points[3];
    int sum;
};

int N, M;
int wood[6][6];
vector <boo_type> boomerang;
vector <boo_type> sums;
int answer;
// 부메랑의 중심이 되는 칸은 강도가 *2 된다
// ■□ □■ □   □
// □   □ ■□ □■

bool compare(boo_type a, boo_type b) {
    
    if(a.sum == b.sum)
        return a.dir < b.dir;
    else
        return a.sum > b.sum;
}

bool isSame(boo_type a) {
    
    for(int i = 0; i<sums.size(); i++) {
        boo_type b = sums[i];
        for(int j =0; j<3; j++)
            for(int k = 0; k<3; k++)
                if(a.points[j] == b.points[k])
                    return true;
    }
    
    return false;
}

void getAnswer() {
    int sum = 0;
    for(int i = 0; i<sums.size(); i++)
        sum += sums[i].sum;
    
    answer = (answer < sum) ? sum : answer;
}

void solve(int idx) {
    for(int i = idx + 1; i<boomerang.size(); i++){
        if(!isSame(boomerang[i])) {
            sums.push_back(boomerang[i]);
            getAnswer();
            solve(i);
            sums.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j =0; j<M; j++)
            cin >> wood[i][j];
    
    if(N < 2 || M < 2) {
        cout << 0;
        return 0;
    }
    
    for(int i = 0; i<N - 1; i++) {
        for(int j =0; j<M - 1; j++)
        {
            // ■□
            // □
            
            boo_type boo;
            boo.dir = 1;
            boo.points[0] = {i, j+1};
            boo.points[1] = {i, j};
            boo.points[2] = {i+1, j};
            boo.sum = wood[boo.points[0].first][boo.points[0].second] +
            wood[boo.points[1].first][boo.points[1].second] * 2 + wood[boo.points[2].first][boo.points[2].second];
            boomerang.push_back(boo);
            
            // □■
            //  □
            
            boo.dir = 2;
            boo.points[0] = {i, j};
            boo.points[1] = {i, j+1};
            boo.points[2] = {i+1, j+1};
            boo.sum = wood[boo.points[0].first][boo.points[0].second] +
            wood[boo.points[1].first][boo.points[1].second] * 2 + wood[boo.points[2].first][boo.points[2].second];
            boomerang.push_back(boo);
            
            // □
            // ■□
            
            boo.dir = 3;
            boo.points[0] = {i, j};
            boo.points[1] = {i+1, j};
            boo.points[2] = {i+1, j+1};
            boo.sum = wood[boo.points[0].first][boo.points[0].second] +
            wood[boo.points[1].first][boo.points[1].second] * 2 + wood[boo.points[2].first][boo.points[2].second];
            boomerang.push_back(boo);
            
            //  □
            // □■
            
            boo.dir = 4;
            boo.points[0] = {i, j+1};
            boo.points[1] = {i+1, j+1};
            boo.points[2] = {i+1, j};
            boo.sum = wood[boo.points[0].first][boo.points[0].second] +
            wood[boo.points[1].first][boo.points[1].second] * 2 + wood[boo.points[2].first][boo.points[2].second];
            boomerang.push_back(boo);
        }
    }
    
    sort(boomerang.begin(), boomerang.end(), compare);
    
    for(int i = 0; i<boomerang.size(); i++)
    {
        boo_type temp = boomerang[i];
        sums.push_back(temp);
        solve(i);
        sums.clear();
    }
    
    cout << answer;
    
    return 0;
}

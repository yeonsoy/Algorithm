#include <iostream>
#include <algorithm>
using namespace std;

// 거북이

typedef pair<int, int> point;

int T;
point dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void setXY(point &lt, point &rb, point pos) {
    if(pos.first <= lt.first)
        lt.first = pos.first;
    if(pos.second >= lt.second)
        lt.second = pos.second;

    if(pos.first >= rb.first)
        rb.first = pos.first;
    if(pos.second <= rb.second)
        rb.second = pos.second;
}

void rotate(int &now_dir, char op) {
    
    if(op == 'L') {
        now_dir++;
        if(now_dir == 4)
            now_dir = 0;
    }
    else {
        now_dir--;
        if(now_dir == -1)
            now_dir = 3;
    }
    
}

int main() {
    
    cin >> T;
    
    for(int i = 0; i<T; i++) {
        
        point lt = make_pair(0, 0);
        point rb = make_pair(0, 0);
        int now_dir = 1;
        point pos = make_pair(0, 0);
        
        string str;
        cin >> str;
        
        for(int j = 0; j<str.size(); j++) {
            switch (str[j]) {
                case 'F':
                    pos.first += dir[now_dir].first;
                    pos.second += dir[now_dir].second;
                    break;
                case 'B' :
                    pos.first -= dir[now_dir].first;
                    pos.second -= dir[now_dir].second;
                    break;
                case 'L':
                    rotate(now_dir, 'L');
                    break;
                case 'R':
                    rotate(now_dir, 'R');
                    break;
                default:
                    break;
            }
            setXY(lt, rb, pos);
        }
        
        cout << abs(lt.first - rb.first) * abs(lt.second - rb.second) << endl;
        
    }
    
    return 0;
}

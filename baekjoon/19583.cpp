#include <iostream>
#include <map>
using namespace std;

// 싸이버개강총회

struct times {
    int h;
    int m;
};

times S, E, Q;
map <string, int> m1, m2;

void setTime(times &T, string str) {
    T.h = (str[0] - '0') * 10 + (str[1] - '0');
    T.m = (str[3] - '0') * 10 + (str[4] - '0');
}

bool isLowerTime(times a, times b) {
    
    if(a.h == b.h)
        return a.m <= b.m;
    else
        return a.h < b.h;
}

int main() {
    
    string a, b, c;
    cin >> a >> b >> c;
    
    setTime(S, a);
    setTime(E, b);
    setTime(Q, c);
    
    string stamp, str;
    times t;
    
    while(!cin.eof()) {
        cin >> stamp >> str;
        
        setTime(t, stamp);
        
        // 개강총회 시작 전 입장 여부
        if(isLowerTime(t, S))
            m1[str]++;
        
        // 개강총회를 끝내고 나서, 스트리밍을 끝낼 때까지
        if(isLowerTime(E, t) && isLowerTime(t, Q)) {
            if(m1[str] > 0)
                m2[str]++;
        }
         if(stamp == "") break;
    }
    
    cout << m2.size() << endl;
    
    return 0;
}

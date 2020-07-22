#include <iostream>
using namespace std;

// 유효기간

int T;

bool isMonth(int n) {
    
    if(n >= 1 && n <= 12)
        return true;
    else return false;
}

int main() {
    
    cin >> T;
    
    for(int i = 0; i<T; i++) {
        
        string date;
        cin >> date;
        
        string answer = "AMBIGUOUS";
        int first = (date[0] - '0') * 10 + (date[1] - '0');
        int second = (date[2] - '0') * 10 + (date[3] - '0');
        
        if(!isMonth(first) && !isMonth(second)) answer = "NA";
        else if(!isMonth(first) && isMonth(second)) answer = "YYMM";
        else if(isMonth(first) && !isMonth(second)) answer = "MMYY";
        
        cout << "#" << i + 1 << " " << answer << endl;
    }
    
    return 0;
}

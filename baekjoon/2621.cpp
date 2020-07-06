#include <iostream>
using namespace std;

// 카드게임

enum color {
    R, B, Y, G
};

int number[10];
int color_cnt[4];
int score;

bool getColor() {
    for(int i = 0; i<4; i++)
        if(color_cnt[i] > 4)
            return true;
    
    return false;
}

void getNumber(bool status, int max_num) {
    
    bool continued = false;
    int two1 = 0;
    int two2 = 0;
    int three = 0;
    int four = 0;
    
    for(int i = 1; i<=9; i++) {
        if(number[i] == 2) {
            if(two1 > 0)
                two2 = i;
            else
                two1 = i;
        }
        
        else if(number[i] == 3)
            three = i;
        
        else if(number[i] == 4)
            four = i;
        
        if(i + 4 <= 10)
            if(number[i] == 1 && number[i + 1] == 1 && number[i + 2] == 1 && number[i + 3] == 1 && number[i + 4] == 1)
                continued  = true;
        
    }
    
    if(status && continued)
        cout << 900 + max_num;
    
    else if(four != 0)
        cout << 800 + four;
    
    else if(three != 0 && two1 != 0)
        cout << 700 + three * 10 + two1;
    
    else if(status)
        cout << 600 + max_num;
    
    else if(continued)
        cout << 500 + max_num;
    
    else if(three != 0)
        cout << 400 + three;
    
    else if(two1 != 0 && two2 != 0)
        cout << 300 + max(two1, two2) * 10 + min(two1, two2);
    
    else if(two1 != 0)
        cout << 200 + two1;
    
    else
        cout << 100 + max_num;
}


int main() {
    
    char c;
    int idx;
    int num = 0;
    for(int i = 0; i<5; i++) {
        cin >> c >> idx;
        switch (c) {
            case 'R':
                color_cnt[R]++;
                break;
            case 'B':
                color_cnt[B]++;
                break;
            case 'Y':
                color_cnt[Y]++;
                break;
            case 'G':
                color_cnt[G]++;
                break;
            default:
                break;
        }
        number[idx]++;
        num = max(num, idx);
    }
    
    getNumber(getColor(), num);
    
    return 0;
}

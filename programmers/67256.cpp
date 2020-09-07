#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 키패드 누르기

typedef pair<int, int> point;

point getPosition(int n) {
    
    if(n == 0)
        return {3, 1};
    else
        return {(n - 1) / 3, (n - 1) % 3};
    
}

int getDiff(point a, point b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    point right_hand = {3, 0};
    point left_hand = {3, 2};
    
    char keyboard[4][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}};
    
    for(int i = 0; i<numbers.size(); i++) {
        
        point target = getPosition(numbers[i]);
        
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer.append("L");
            left_hand = target;
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer.append("R");
            right_hand = target;
        }
        else {
            
            int left_length = getDiff(left_hand, target);
            int right_length = getDiff(right_hand, target);
            if(left_length == right_length)
            {
                if(hand == "right") {
                    answer.append("R");
                    right_hand = target;
                }
                else {
                    answer.append("L");
                    left_hand = target;
                }
            }
            else if(left_length < right_length) {
                answer.append("L");
                left_hand = target;
            }
            else
            {
                answer.append("R");
                right_hand = target;
            }
            
        }
    }
    
    return answer;
}


int main() {
    
    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
    
    return 0;
}

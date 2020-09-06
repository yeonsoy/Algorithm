#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 수식 최대화
// 0 : +, 1 : -, 2 : *

long long answer = 0;
int priority_oper[3];
bool isUsed[3];
vector <char> op;
vector <long long> num;

char getOperator(int idx) {
    
    if(idx == 0)
        return '+';
    else if(idx == 1)
        return '-';
    else
        return '*';
}

long long result(char oper, long long a, long long b) {
    
    if(oper == '+')
        return a + b;
    else if(oper == '-')
        return a - b;
    else
        return a * b;
}

long long calculation() {
    
    vector <char> op2(op);
    vector <long long> num2(num);
    
    int p_oper = 0;
    int idx = 0;
    
    while(true) {
        
        if(idx == 3) break;
        
        for(int i = 0; i<3; i++)
            if(priority_oper[i] == idx)
                p_oper = i;
        
        int cur = -1;
        for(int i = 0; i<op2.size(); i++) {
            if(op2[i] == getOperator(p_oper))
            {
                cur = i;
                break;
            }
        }
        
        if(cur == -1) {
            idx ++;
            continue;
        }
        
        long long temp = result(op2[cur], num2[cur], num2[cur + 1]);
        num2[cur] = temp;
        num2.erase(num2.begin() + cur + 1);
        op2.erase(op2.begin() + cur);
        
    }
    
    return abs(num2[0]);
}

void setPriorityOper(int idx) {
    
    if(idx == 3) {
        long long res = calculation();
        answer = max(res, answer);
        return ;
    }
    
    for(int i = 0; i<3; i++) {
        if(!isUsed[i]) {
            isUsed[i] = true;
            priority_oper[idx] = i;
            setPriorityOper(idx + 1);
            priority_oper[idx] = -1;
            isUsed[i] = false;
        }
    }
}

long long solution(string expression) {
    string cur = "";
    
    for(int i = 0; i<expression.size(); i++) {
        if(expression[i] >= '0' && expression[i] <= '9')
            cur += expression[i];
        else {
            op.push_back(expression[i]);
            num.push_back(stoi(cur));
            cur = "";
        }
    }
    
    num.push_back(stoi(cur));
    
    for(int i = 0; i<3; i++)
        priority_oper[i] = -1;
    
    setPriorityOper(0);
    
    return answer;
}

int main() {
    
    cout << solution("100-200*300-500+20");
    
    return 0;
}

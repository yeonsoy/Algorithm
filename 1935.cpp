#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 후위 표기식2

stack <double> num_str;
float answer = 0;
int *nums;

bool isArithmetic(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return true;
    else
        return false;
}

void calc(char ch)
{
    double a = num_str.top();
    num_str.pop();
    double b = num_str.top();
    num_str.pop();

    switch (ch)
    {
    case '+':
        num_str.push(a + b);
        break;
    case '-':
        num_str.push(b - a);
        break;
    case'/':
        num_str.push(b / a);
        break;
    case '*':
        num_str.push(a * b);
        break;
    default:
        break;
    }
}

int main()
{
    int N;
    string str;


    cin >> N >> str;

    nums = new int[N];


    for (int i = 0; i < N; i++)
        cin >> nums[i];

    for (int i = 0; str[i]; i++)
    {
        if (!isArithmetic(str[i]))
            num_str.push(nums[str[i] - 'A']);
        else
            calc(str[i]);
    }

    printf("%.2f", num_str.top());
    num_str.pop();

    return 0;
}

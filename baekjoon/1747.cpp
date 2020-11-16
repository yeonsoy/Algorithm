#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

// 소수&팰린드롬

int N;
bool era[1003002];

void getEratos() {
    era[0] = era[1] = true;
    for (int i = 2; i < 1003002; i++)
        if (era[i] == false)
            for (int j = i + i; j < 1003002; j += i)
                era[j] = true;
}

bool isPrime(int n)
{
    return !era[n];
}

bool isPalindrome(int n)
{
    string number = to_string(n);

    for (int i = 0; i < number.size() / 2; i++)
        if (number[i] != number[number.size() - 1 - i])
            return false;

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    getEratos();
    
    for (int i = N; i < 1003002; i++)
        if (isPrime(i) && isPalindrome(i))
        {
            cout << i << "\n";
            break;
        }

    return 0;
}

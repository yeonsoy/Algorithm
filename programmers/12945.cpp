#include <string>
#include <vector>

using namespace std;

// 피보나치 수

int number[100001];

int fibo(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (number[n] != 0)
        return number[n];
    else
        return number[n] = (fibo(n - 1) + fibo(n - 2)) % 1234567;
}

int solution(int n) {
    return fibo(n);
}
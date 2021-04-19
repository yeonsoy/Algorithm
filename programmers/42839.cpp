#include <string>
#include <vector>
#include <set>

using namespace std;

// 소수 찾기

set <int> number;
bool isUsed[8];

bool isPrime(long long n)
{
    if (n == 0 || n == 1)
        return false;

    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}


long long getNumber(string num) {
    long long res = 0;
    long long idx = 1;
    for (int i = num.size() - 1; i >= 0; i--) {
        res += (num[i] - '0') * idx;
        idx *= 10;
    }

    return res;
}

void makeNumber(string num, string n) {
    if (n.size() > 0 && n.size() <= num.size()) {
        long long temp = getNumber(n);
        if (isPrime(temp))
            number.insert(temp);
    }

    for (int i = 0; i < num.size(); i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            makeNumber(num, n + num[i]);
            isUsed[i] = false;
        }
    }

}

int solution(string numbers) {
    int answer = 0;

    makeNumber(numbers, "");
    answer = number.size();

    return answer;
}
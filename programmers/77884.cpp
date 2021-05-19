#include <string>
#include <vector>
using namespace std;

// 약수의 개수와 덧셈

bool isOddFactor(int n) {
    int res = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0) {
            res++;

            if (i * i < n)
                res++;
        }
    }

    return (res % 2 == 1);
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++)
        if (isOddFactor(i))
            answer -= i;
        else
            answer += i;

    return answer;
}
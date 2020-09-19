#include <string>
#include <vector>
#include <math.h>
using namespace std;

// 소수 찾기

int solution(int n) {
    int answer = 0;
    int* arr = new int[n + 1];
    
    for (int i = 2; i <= n; i++)
            arr[i] = i;
    
    int sqrt_n = (int) sqrt(n);
    
     for (int i = 2; i <= sqrt_n; i++) {
            if (arr[i] == 0)
                continue;
    
            for (int j = i + i; j <= n; j += i)
                arr[j] = 0;
     }
    
        for (int i = 2; i <= n; i++) {
            if (arr[i] != 0)
                answer++;
            }
    
    return answer;
}

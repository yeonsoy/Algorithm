#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// 정수 제곱근 판별

long long solution(long long n) {
    long long answer = 0;
    
    if((int)(sqrt(n)) != (double)(sqrt(n)))
        return -1;
    else
        answer = (long long)(sqrt(n) + 1) * (long long)(sqrt(n) + 1);
    
    return answer;
}

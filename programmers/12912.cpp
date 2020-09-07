#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 두 정수 사이의 합

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a < b)
    {
        for(int i = a; i<=b ; i++)
            answer += i;
    }
    else
    {
         for(int i = b; i<=a ; i++)
            answer += i;
    }
        
    return answer;
}

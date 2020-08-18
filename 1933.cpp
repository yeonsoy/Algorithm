#include <stdio.h>

// 간단한 N 의 약수

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i<=n; i++)
    {
        if(n % i == 0)
            printf("%d ", i);
    }
    return 0;
}
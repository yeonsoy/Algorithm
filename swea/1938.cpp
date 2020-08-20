#include <stdio.h>

// 아주 간단한 계산기

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("%d\n", a+b);
    printf("%d\n", a-b);
    printf("%d\n", a*b);
    printf("%d\n", a/b);
    
    return 0;
}

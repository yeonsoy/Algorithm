#include <stdio.h>

// 거꾸로 출력해 보아요

int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i = n; i >= 0; i--)
        printf("%d ", i);
    
    return 0;
}

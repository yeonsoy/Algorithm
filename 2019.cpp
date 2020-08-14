#include <stdio.h>

// 더블더블

int main()
{
    int n;
    int answer = 1;
    scanf("%d", &n);
    
    for(int i = 0; i <= 8; i++)
    {
        printf("%d ", answer);
        answer *= 2;
    }
    
    return 0;
}

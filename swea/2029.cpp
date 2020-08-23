#include <stdio.h>

// 몫과 나머지 출력하기

int main()
{
    int num;
    scanf("%d", &num);
    
    for(int i =1; i<=num; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        printf("#%d %d %d\n", i, a/b, a%b);
    }
    
    return 0;
}

#include <stdio.h>

// 1대1 가위바위보

int main()
{
    // 가위 1 바위 2 보 3
    
    int a, b;
    scanf("%d %d", &a, &b);
    
    switch(a)
    {
        case 1 :
            if(b == 2)
                printf("B");
            else
                printf("A");
            break;
        case 2 :
            if(b == 1)
                printf("A");
            else
                printf("B");
            break;
        case 3 :
            if(b == 2)
                printf("A");
            else
                printf("B");
            break;
    }
    
    return 0;
}

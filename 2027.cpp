#include <stdio.h>

// 대각선 출력하기

int main()
{
    for(int i =0; i<5; i++)
    {
        for(int k =0; k<5; k++)
        {
            if(i == k)
                printf("#");
            else
                printf("+");
        }
        printf("\n");
    }
    return 0;
}

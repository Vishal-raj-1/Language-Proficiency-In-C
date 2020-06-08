#include<stdio.h>

int main()
{
    int count[10] = {0};
    char c;

    while(scanf("%c",&c))
    {
        if(c == '\n')
            break;
            
        if(c >= '0' && c <= '9')
            count[c - '0']++;
    }

    for(int i=0; i<10; i++)
        printf("%d ",*(count+i));

    return 0;
}
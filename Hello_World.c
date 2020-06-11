#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    gets(s);//scanf("%[^\n]%*c", s) is preferred
    
    printf("Hello, World!\n%s",s);
    
    return 0;
}

#include<stdio.h>

int main()
{
    char s[50],str[100],c;
    
    scanf("%c",&c);
    scanf(" %s",s);
    scanf(" %[^\n]%*c",str);
    
    printf("%c\n%s\n%s\n",c,s,str);
    
    return 0;
}

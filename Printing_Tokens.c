#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *arr = malloc(1024*sizeof(char));

    scanf("%[^\n]%*c",arr);
    int len = strlen(arr);

    arr = realloc(arr,len + 1);

    for(int i=0; i < len; i++)
    {
        if(arr[i] == ' ')
           arr[i] = '\n';
    }
    
    for(int i=0; i<len; i++)
        printf("%c",*(arr+i));

    free(arr);

    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int next_permutation(int n,char **s)
{
    int i = n-1, j = n-1;

    while(i > 0 && strcmp(s[i-1],s[i]) >= 0)
        i--;

    if(i <= 0)
        return 0;

    while(strcmp(s[i-1],s[j]) >= 0)
        j--;

    char *temp = s[j];
    s[j] = s[i-1];
    s[i-1] = temp;

    j = n-1;

    while(i < j)
    {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;

        i++;
        j--;
    }
    return 1;
}

int main()
{
    int n;
    char **s;

    scanf("%d",&n);

    s = calloc(n,sizeof(char*));

    for(int i=0; i<n; i++)
    {
        s[i] = calloc(11,sizeof(char));
        scanf("%s",s[i]);
    }

    do {

        for(int i=0; i<n; i++)
            printf("%s%c",s[i],i == n-1 ? '\n' : ' ');

    } while(next_permutation(n,s));

    for(int i=0; i<n; i++)
        free(s[i]);

    free(s);

    return 0;
}

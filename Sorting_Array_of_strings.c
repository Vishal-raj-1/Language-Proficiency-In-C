#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lexicographic_sort(const char* a,const char *b)
{
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a,const char *b)
{
    return strcmp(b,a);
}

int sort_by_length(const char* a,const char *b)
{
    int res = strlen(a) - strlen(b);

    return (res) ? res : lexicographic_sort(a,b);
}

int distinct_char(const char *a)
{
    int distinct = 0,alpha[26] = {0};

    for(int i=0; a[i]; i++)
    {
        alpha[a[i]-'a']++;
    }

    for(int i=0; i<26; i++)
    {
        if(alpha[i])
            distinct++;
    }

    return distinct;
}

int sort_by_number_of_distinct_characters(const char* a,const char *b)
{
    int res = distinct_char(a) - distinct_char(b);

    return (res) ? res : lexicographic_sort(a,b);
}

//Bubble-Sort
void string_sort(char **arr,const int len,int (*cmp_func)(const char *a,const char *b))
{
    int flag = 0;
    int top = len - 1;

    while(! flag)
    {
        flag = 1;
        for(int i=0; i<top; i++)
        {
            if(cmp_func(arr[i],arr[i+1]) > 0)
            {
                char *temp = arr[i];
                arr[i]  = arr[i+1];
                arr[i+1] = temp;

                flag = 0;
            }
        }
        top-- ;
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    char **arr = (char **)malloc(n * sizeof(char *));

    for(int i=0; i<n ; i++)
    {
        arr[i] = (char *)malloc(1024 * sizeof(char));

        scanf("%s",arr[i]);

        arr[i] = (char *)realloc(arr[i],strlen(arr[i]) + 1);
    }

    string_sort(arr,n,lexicographic_sort);

    for(int i = 0; i<n ; i++)
        printf("%s\n",arr[i]);
    printf("\n");

    string_sort(arr,n,lexicographic_sort_reverse);

    for(int i = 0; i<n ; i++)
        printf("%s\n",arr[i]);
    printf("\n");

    string_sort(arr,n,sort_by_length);

    for(int i = 0; i<n ; i++)
        printf("%s\n",arr[i]);
    printf("\n");

    string_sort(arr,n,sort_by_number_of_distinct_characters);

    for(int i = 0; i<n ; i++)
        printf("%s\n",arr[i]);
    printf("\n");

    for(int i=0 ; i < n; i++)
        free(arr[i]);

    free(arr);

    return 0;
}

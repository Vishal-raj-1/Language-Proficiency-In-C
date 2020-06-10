#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,temp;
    scanf("%d",&n);
 
    //DAM & initialise it with 0
   int *arr = (int *)calloc(n,sizeof(int));

    for(int i=0; i<n; i++)
        scanf("%d",(arr+i));

    for(int i=0; i<n/2; i++)
    {
        temp = arr[n-1-i];
        arr[n-1-i] = arr[i];
        arr[i] = temp;
    }

    for(int i=0; i<n; i++)
        printf("%d ",*(arr+i));

    //delete the DAM
    free(arr);

    return 0;
}

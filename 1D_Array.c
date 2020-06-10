#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,sum = 0;
    scanf("%d",&n);
    
    //dynamically allocate the memory and initialise with 0
    int *arr = (int *)calloc(n,sizeof(int));
    
    for(int i=0;i<n;i++)
    {
      scanf("%d",(arr+i));  
    
       sum += *(arr+i);
    }
    
    printf("%d\n",sum);
    
    //delete the dynamically allocated memory
    free(arr);
    return 0;
}

#include<stdio.h>

void calculate_the_maximum(int n,int k)
{
   int and = 0,or = 0,xor = 0;

   for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
                if((xor < (j^i)) && ((j^i) < k))
                    xor = j^i;
            
                if((and < (j&i)) && ((j&i) < k))
                    and = j&i;
            
                if((or < (j|i)) && ((j|i) < k))
                    or = j|i;
        }
    }
    
    printf("%d\n%d\n%d\n",and,or,xor);
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    calculate_the_maximum(n,k);
    
    return 0;
}
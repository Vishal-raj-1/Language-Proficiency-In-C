#include<stdio.h>

int main()
{
    int n,temp;
    scanf("%d",&n);

    temp = n;
    int p[2*n-1][2*n-1];

    for(int i=0; i<2*n-1; i++)
    {
        for(int k = i; k < 2*n-1-i ; k++)
            p[i][k] = temp;

        for(int k = 2*n-2-i; k > i ; k--)
            p[k][2*n-2-i] = temp;

        for(int k = 2*n-3-i ; k >= i ; k--)
            p[2*n-2-i][k] = temp;

        for(int k = 2*n-3-i ; k > i ; k--)
            p[k][i] = temp;

        temp--;
    }

    for(int i = 0; i<2*n-1 ; i++)
    {
        for(int j=0; j < 2*n-1 ; j++)
            printf("%d ",p[i][j]);
        printf("\n");
    }

    return 0;
}

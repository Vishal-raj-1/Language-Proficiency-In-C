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

// Solution 2: Find the shortest distance of (i,j) from four sides and then print n - shortest_distance. 
#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() 
{
    int n;
    scanf("%d", &n);
    int len = n * 2 - 1;
    for(int row = 0; row < len; row++)
    {
        for(int col = 0; col < len; col++)
        {
            int m = min(row, col);
            m = min(m, len - row - 1);
            m = min(m, len - col - 1);
            printf("%d ", n - m);
        }
        printf("\n");
    }
    return 0;
}

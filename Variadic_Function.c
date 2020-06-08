#include<stdio.h>
#include<stdarg.h>
//Variadic Function

int sum(int count,...)
{
    int Sum = 0;
    va_list list;
    va_start(list,count);

    for(int i=0; i<count ; i++)
    {
        Sum += va_arg(list,int);
    }
    va_end(list);
    return Sum;
}

int min(int count,...)
{
    int Min = 1000000,temp;
    va_list list;
    va_start(list,count);

    for(int i=0; i<count ; i++)
    {
        temp = va_arg(list,int);
        if(Min > temp)
            Min = temp;
    }
    
    va_end(list);
    return Min;
}

int max(int count,...)
{
    int Max = 1,temp;
    va_list list;
    va_start(list,count);

    for(int i=0; i<count ; i++)
    {
        temp = va_arg(list,int);
        if(Max < temp)
            Max = temp;
    }
    
    va_end(list);
    return Max;
}

int main()
{
    printf("Sum = %d\n",sum(3,5,7,8));
    printf("Sum = %d\n",sum(5,5,7,8,10,12));


    printf("Min = %d\n",min(3,5,7,8));
    printf("Min = %d\n",min(5,5,7,8,3,12));

    printf("Max = %d\n",max(3,5,7,8));
    printf("Max = %d\n",max(5,5,7,8,10,12));
    return 0;
}
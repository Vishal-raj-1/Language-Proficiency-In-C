#include<stdio.h>
#include<stdlib.h>

int marks_summation(int *marks,int number_of_students,char gender)
{
    int sum = 0;
    if(gender == 'g')
    {
        for(int girls = 1; girls < number_of_students ; girls += 2)
            sum += marks[girls];
    }
    else
    {
        for(int boys = 0; boys < number_of_students ; boys += 2)
            sum += marks[boys];
    }

    return sum;
}

int main()
{
    int number_of_students,sum;
    char gender;

    scanf("%d",&number_of_students);

    int *marks = (int *)malloc(number_of_students * sizeof(int));

    for(int student = 0; student < number_of_students ; student++)
        scanf("%d",&marks[student]);

    scanf(" %c",&gender);

    sum = marks_summation(marks,number_of_students,gender);
    printf("%d\n",sum);

    free(marks);

    return 0;
}

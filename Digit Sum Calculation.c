#include <stdio.h>
#include <stdlib.h>

//1556 - Συγκούνας Ιωάννης
//1573 - Χανός Στέφανος

int findDigits1(int number) // Recursive Function
{
    int sum = 0;

    if(number == 0)
    {
        return 0;
    }
    else
    {
        sum = sum + number % 10 + findDigits1(number / 10);
    }
    return sum;
}

int findDigits2(int number) // Non-Recursive Function
{
    int sum = 0;

    while (number != 0) 
    {
        sum = sum + number % 10;
        number = number / 10;
    }
    return sum;
}

int main()
{
    int number;
    printf("Please enter a non negative number \n");
    scanf("%d" , &number);

    while(number < 0)
    {
        printf("You have entered a negative number , please enter a positive one \n");
        scanf("%d" , &number);
    }

    printf("\nThe number you chose is: [%d] \n" , number);
    printf("The sum of the number's digits (WITHOUT recursion) is: [%d] \n" , findDigits2(number));
    printf("The sum of the number's digits (WITH recursion) is: [%d] \n" , findDigits1(number));
    return 0;
}
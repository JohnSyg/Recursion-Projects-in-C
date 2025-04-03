#include <stdio.h>
#include <stdlib.h>

//1556 - Συγκούνας Ιωάννης
//1573 - Χανός Στέφανος

int puzzle1(int Pieces , int Levels) // Recursive Function
{
    if(Pieces <= 0)
    {
        return Levels;
    }

    Levels += 1;
    if(Levels == 1)
    {
        Pieces -= 1;  
    }
    puzzle1(Pieces - (8*(Levels-1)) , Levels);
}

int puzzle2(int Pieces , int Levels) // Non-Recursive Function
{
    while(Pieces>0)
    {
        Levels += 1;
        if(Levels == 1)
        {
            Pieces -= 1;
        }
        Pieces = Pieces - (8*(Levels-1));
    } 
    return Levels;
}

int main()
{
    int Pieces = 0;
    int Levels = 0; 
    
    printf("Please enter the number of pieces that are available \n");
    scanf("%d" , &Pieces);

    while(Pieces<0)
    {
        printf("The number of pieces cant negative , please enter a positive number \n");
        scanf("%d" , &Pieces);
    }

    printf("The levels needed for the amount of pieces you entered (WITHOUT recursion) are: [%d] \n" , puzzle2(Pieces , Levels));
    printf("The levels needed for the amount of pieces you entered (WITH recursion) are: [%d] \n" , puzzle1(Pieces , Levels));

    return 0;
}